#include "BulletUpdateComponent.h"
#include <cstdlib>
#include <ctime>
#include <SFML/System/Vector2.hpp>
#include "WorldState.h"

void BulletUpdateComponent::spawnForPlayer(sf::Vector2f position)
{
	m_MovingUp  = true;
	m_IsSpawned = true;
	m_BelongsToPlayer = true;

	m_TransformComponent->getLocation() = position;
	m_TransformComponent->getLocation().y -= m_TransformComponent->getSize().y;

	m_RectColliderComponent->setColliderRect({ m_TransformComponent->getLocation(), m_TransformComponent->getSize() });
}

void BulletUpdateComponent::spawnForInvader(sf::Vector2f position)
{
	m_MovingUp = false;
	m_IsSpawned = true;
	m_BelongsToPlayer = false;

	m_TransformComponent->getLocation() = position;
	m_RectColliderComponent->setColliderRect({ m_TransformComponent->getLocation(), m_TransformComponent->getSize() });

	srand(time(0));
	m_AlienBulletSpeedModifier = (rand() % m_ModifierRandomComponent) + m_MinimumAdditionalModifier;
}

void BulletUpdateComponent::deSpawn()
{
	m_IsSpawned = false;
}

bool BulletUpdateComponent::isMovingUp()
{
	return m_MovingUp;
}

void BulletUpdateComponent::update(float delta)
{	
	if (!m_IsSpawned)
	{
		return;
	}
	
	if (m_MovingUp)
	{
		m_TransformComponent->getLocation().y -= m_Speed * delta;
	}
	else
	{
		m_TransformComponent->getLocation().y += m_Speed / m_AlienBulletSpeedModifier * delta;
	}

	if (m_TransformComponent->getLocation().y > WorldState::WORLD_HEIGHT ||
		m_TransformComponent->getLocation().y < -2)
	{
		deSpawn();
	}

	m_RectColliderComponent->setColliderRect({
		m_TransformComponent->getLocation(),
		m_TransformComponent->getSize()
	})
}
