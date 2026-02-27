#include "UpdateComponent.h"
#include <string>

std::string UpdateComponent::getType()
{
	return m_Type;
}

std::string UpdateComponent::getSpecificType()
{
	return std::string();
}

void UpdateComponent::enable()
{
	m_Enabled = true;
}

void UpdateComponent::disable()
{
	m_Enabled = false;
}

bool UpdateComponent::enabled()
{
	return m_Enabled;
}

void UpdateComponent::start(GameObjectSharer* gameObjectSharer, GameObject* parent)
{
}
