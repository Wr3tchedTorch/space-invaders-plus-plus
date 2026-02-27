#include "PlayerUpdateComponent.h"
#include <SFML/Window/Joystick.hpp>
#include "WorldState.h"

void PlayerUpdateComponent::update(float delta)
{
	if (sf::Joystick::isConnected(0))
	{
		m_TransformComponent->getLocation().x += ((m_Speed / 100) * m_ExtendX) * delta;
		m_TransformComponent->getLocation().y += ((m_Speed / 100) * m_ExtendY) * delta;
	}

	if (m_IsHoldingLeft)
	{
		m_TransformComponent->getLocation().x -= m_Speed * delta;
	}
	else if (m_IsHoldingRight)
	{
		m_TransformComponent->getLocation().x += m_Speed * delta;
	}

	if (m_IsHoldingUp)
	{
		m_TransformComponent->getLocation().y -= m_Speed * delta;
	}
	else if (m_IsHoldingDown)
	{
		m_TransformComponent->getLocation().y += m_Speed * delta;
	}

	float limitX = WorldState::WORLD_WIDTH  - m_TransformComponent->getSize().x;
	float limitY = WorldState::WORLD_HEIGHT - m_TransformComponent->getSize().y;

	if (m_TransformComponent->getLocation().x > limitX)
	{
		m_TransformComponent->getLocation().x = limitX;
	}
	else if (m_TransformComponent->getLocation().x < 0)
	{
		m_TransformComponent->getLocation().x = 0;
	}

	if (m_TransformComponent->getLocation().y > limitY)
	{
		m_TransformComponent->getLocation().y = limitY;
	}
	else if (m_TransformComponent->getLocation().y < WorldState::WORLD_HEIGHT / 2.0f)
	{
		m_TransformComponent->getLocation().y = WorldState::WORLD_HEIGHT / 2.0f;
	}

	m_RectColliderComponent->setColliderRect({ m_TransformComponent->getLocation(), m_TransformComponent->getSize() });
}

void PlayerUpdateComponent::updateShipTravelWithController(sf::Vector2f direction)
{
	m_ExtendX = direction.x;
	m_ExtendY = direction.y;
}

void PlayerUpdateComponent::moveRight()
{
	m_IsHoldingRight = true;
	stopLeft();
}

void PlayerUpdateComponent::moveLeft()
{
	m_IsHoldingLeft = true;
	stopRight();
}

void PlayerUpdateComponent::moveUp()
{
	m_IsHoldingUp = true;
	stopDown();
}

void PlayerUpdateComponent::moveDown()
{
	m_IsHoldingDown = true;
	stopUp();
}

void PlayerUpdateComponent::stopRight()
{
	m_IsHoldingRight = false;
}

void PlayerUpdateComponent::stopLeft()
{
	m_IsHoldingLeft = false;
}

void PlayerUpdateComponent::stopDown()
{
	m_IsHoldingDown = false;
}

void PlayerUpdateComponent::stopUp()
{
	m_IsHoldingUp = false;
}
