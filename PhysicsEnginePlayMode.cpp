#include "PhysicsEnginePlayMode.h"
#include <vector>
#include "GameObject.h"
#include "GameObjectSharer.h"
#include "BulletUpdateComponent.h"
#include <memory>
#include "SoundEngine.h"
#include <SFML/System/Vector2.hpp>
#include "WorldState.h"
#include "InvaderUpdateComponent.h"
#include "PlayerUpdateComponent.h"

void PhysicsEnginePlayMode::detectInvaderCollisions(std::vector<GameObject>& objects, const std::vector<int>& bulletPositions)
{
	sf::Vector2f offScreen({ -1, -1 });

	for (auto& invader : objects)
	{
		if (invader.getTag() != "invader" || !invader.isActive())
		{
			continue;
		}
		for (auto& bulletIndex : bulletPositions)
		{
			auto& bullet = objects.at(bulletIndex);
			if (bullet.getTag() != "bullet" || !std::static_pointer_cast<BulletUpdateComponent>(bullet.getFirstUpdateComponent())->m_BelongsToPlayer)
			{
				continue;
			}

			bool colided = bullet.getEncompassingRectCollider().findIntersection(invader.getEncompassingRectCollider()).has_value();
			if (!colided)
			{
				continue;
			}

			SoundEngine::playInvaderExplosion();
			invader.getTransformComponent()->getLocation() = offScreen;
			bullet.getTransformComponent()->getLocation()  = offScreen;

			WorldState::SCORE++;
			WorldState::NUM_INVADERS--;

			invader.setInactive();
		}
	}
}

void PhysicsEnginePlayMode::detectPlayerCollisionsAndInvaderDirection(std::vector<GameObject>& objects, const std::vector<int>& bulletPositions)
{
	sf::Vector2f offScreen({ -1, -1 });

	auto playerTransform = m_Player->getTransformComponent();
	auto playerCollider  = m_Player->getEncompassingRectCollider();
	auto playerLocation  = playerTransform->getLocation();

	for (auto& object : objects)
	{
		if (!object.isActive() || !object.hasCollider() || object.getTag() == "player")
		{
			continue;
		}

		auto& objectCollider  = object.getEncompassingRectCollider();
		auto  objectTransform = object.getTransformComponent();
		auto& objectLocation  = objectTransform->getLocation();
		auto  objectTag		  = object.getTag();
		auto& objectSize      = objectTransform->getSize();
		
		if (objectCollider.findIntersection(playerCollider))
		{
			if (objectTag == "bullet")
			{
				SoundEngine::playPlayerExplosion();
				WorldState::LIVES--;
				objectLocation = offScreen;
				continue;
			}
			if (objectTag == "invader")
			{
				SoundEngine::playPlayerExplosion();
				SoundEngine::playInvaderExplosion();
				WorldState::LIVES--;

				objectLocation = offScreen;
				object.setInactive();
				WorldState::NUM_INVADERS--;
				WorldState::SCORE++;
				continue;
			}
		}

		if (objectTag != "invader")
		{
			continue;
		}		

		auto invaderUpdateComponent = std::static_pointer_cast<InvaderUpdateComponent>(object.getFirstUpdateComponent());
		if (!m_NeedToDropDownAndReverse && !m_InvaderHitWallThisFrame)
		{
			if (objectLocation.x >= WorldState::WORLD_WIDTH - objectSize.x &&
				invaderUpdateComponent->isMovingRight())
			{
				m_InvaderHitWallThisFrame = true;
			}
			else if (objectLocation.x < 0 && !invaderUpdateComponent->isMovingRight())
			{
				m_InvaderHitWallThisFrame = true;
			}
		}
		else if (m_NeedToDropDownAndReverse && !m_InvaderHitWallPreviousFrame)
		{
			if (object.hasUpdateComponent())
			{
				invaderUpdateComponent->dropDownAndReverse();
			}
		}
	}	
}

void PhysicsEnginePlayMode::handleInvaderDirection()
{
	if (m_InvaderHitWallThisFrame)
	{
		m_NeedToDropDownAndReverse = true;
		m_InvaderHitWallThisFrame  = false;
	}
	else
	{
		m_NeedToDropDownAndReverse = false;
	}
}

void PhysicsEnginePlayMode::initialize(GameObjectSharer& gameObjectSharer)
{
	m_Player = &gameObjectSharer.findFirstObjectWithTag("player");

	m_PlayerUpdateComponent = std::static_pointer_cast<PlayerUpdateComponent>(m_Player->getComponentByTypeAndSpecificType("update", "player"));
}

void PhysicsEnginePlayMode::detectCollisions(std::vector<GameObject>& objects, const std::vector<int>& bulletPositions)
{
	detectInvaderCollisions(objects, bulletPositions);
	detectPlayerCollisionsAndInvaderDirection(objects, bulletPositions);
	handleInvaderDirection();
}
