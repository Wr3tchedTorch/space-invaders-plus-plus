#include "PhysicsEnginePlayMode.h"
#include <vector>
#include "GameObject.h"
#include "GameObjectSharer.h"
#include "BulletUpdateComponent.h"
#include <memory>
#include "SoundEngine.h"
#include <SFML/System/Vector2.hpp>
#include "WorldState.h"

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

void PhysicsEnginePlayMode::initialize(GameObjectSharer& gameObjectSharer)
{
}
