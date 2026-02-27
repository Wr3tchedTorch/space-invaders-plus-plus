#include "RectColliderComponent.h"
#include <string>
#include <SFML/Graphics/Rect.hpp>

RectColliderComponent::RectColliderComponent(std::string tag)
{
	m_Tag = tag;
}

std::string RectColliderComponent::getColliderTag()
{
	return m_Tag;
}

void RectColliderComponent::setColliderRect(sf::FloatRect rect)
{
	m_CollisionRect = rect;
}

const sf::FloatRect& RectColliderComponent::getColliderRect()
{
	return m_CollisionRect;
}
