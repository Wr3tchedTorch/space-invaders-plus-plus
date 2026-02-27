#include "GraphicsComponent.h"

std::string GraphicsComponent::getType()
{
    return m_Type;
}

std::string GraphicsComponent::getSpecificType()
{
    return std::string();
}

void GraphicsComponent::enable()
{
    m_Enabled = true;
}

void GraphicsComponent::disable()
{
    m_Enabled = false;
}

bool GraphicsComponent::enabled()
{
    return m_Enabled;
}

void GraphicsComponent::start(GameObjectSharer* gameObjectSharer, GameObject* parent)
{
}
