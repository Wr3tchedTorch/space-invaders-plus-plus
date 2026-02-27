#include "InvaderUpdateComponent.h"
#include "SoundEngine.h"
#include <cstdlib>
#include "WorldState.h"
#include <SFML/System/Vector2.hpp>

void InvaderUpdateComponent::dropDownAndReverse()
{
	m_MovingRight = !m_MovingRight;
	m_TransformComponent->getLocation().y += m_TransformComponent->getSize().y;
	m_Speed = (WorldState::WAVE_NUMBER + WorldState::NUM_INVADERS_AT_START - WorldState::NUM_INVADERS) * m_SpeedModifier;
}

bool InvaderUpdateComponent::isMovingRight()
{
	return m_MovingRight;
}

void InvaderUpdateComponent::initializeBulletSpawner(BulletSpawner bulletSpawner, int randSeed)
{
	m_BulletSpawner = bulletSpawner;
	m_RandSeed = randSeed;

	srand(randSeed);
	m_TimeBetweenShots = rand() % 15 + randSeed;
	
	m_AccuracyModifier  = rand() % 2;
	m_AccuracyModifier += rand() / (static_cast<float>(RAND_MAX) / 10.0f);
}

void InvaderUpdateComponent::update(float delta)
{
	if (m_MovingRight)
	{
		m_TransformComponent->getLocation().x += m_Speed * delta;
	}
	else
	{
		m_TransformComponent->getLocation().x -= m_Speed * delta;
	}

	m_RectColliderComponent->setColliderRect({ m_TransformComponent->getLocation(), m_TransformComponent->getSize() });

	m_TimeSinceLastShot += delta;

	bool isPlayerBelow =
		m_TransformComponent->getLocation().x + m_TransformComponent->getSize().x / 2 
			> m_PlayerTransformComponent->getLocation().x - m_AccuracyModifier &&
		m_TransformComponent->getLocation().x + m_TransformComponent->getSize().x / 2 
			< m_PlayerTransformComponent->getLocation().x + m_PlayerTransformComponent->getSize().x + m_AccuracyModifier;

	if (isPlayerBelow && m_TimeSinceLastShot > m_TimeBetweenShots)
	{
		m_TimeSinceLastShot = 0;
		
		SoundEngine::playShoot();
		sf::Vector2f bulletSpawnLocation(m_TransformComponent->getLocation());
		bulletSpawnLocation.x += m_TransformComponent->getSize().x / 2;
		bulletSpawnLocation.y += m_TransformComponent->getSize().y;

		m_BulletSpawner->spawnBullet(bulletSpawnLocation, false);

		srand(m_RandSeed);
		m_TimeBetweenShots = ((rand() % 10) + 1.0f) / WorldState::WAVE_NUMBER;
	}
}
