#include "ColliderComponent.h"
#include <string>

std::string ColliderComponent::getType()
{
    return m_Type;
}

std::string ColliderComponent::getSpecificType()
{
    return std::string();
}

void ColliderComponent::enable()
{
    m_Enabled = true;
}

void ColliderComponent::disable()
{
    m_Enabled = false;
}

bool ColliderComponent::enabled()
{
    return m_Enabled;
}

void ColliderComponent::start(GameObjectSharer* gameObjectSharer, GameObject* parent)
{
}
