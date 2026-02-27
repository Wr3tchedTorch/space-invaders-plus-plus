#include "TransformComponent.h"
#include <string>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

TransformComponent::TransformComponent(sf::FloatRect bounds)
{
    m_Bounds = bounds;
}

sf::Vector2f& TransformComponent::getSize()
{
    return m_Bounds.size;
}

sf::Vector2f& TransformComponent::getLocation()
{
    return m_Bounds.position;
}

std::string TransformComponent::getType()
{
    return m_Type;
}

std::string TransformComponent::getSpecificType()
{
    return m_Type;
}

