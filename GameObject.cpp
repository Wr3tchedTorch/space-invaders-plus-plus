#include "GameObject.h"
#include <memory>
#include "UpdateComponent.h"
#include <iostream>
#include <format>
#include "RectColliderComponent.h"
#include <string>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Component.h"
#include "GraphicsComponent.h"
#include "TransformComponent.h"

void GameObject::update(float delta)
{
	if (!m_isActive || !m_HasUpdateComponent)
	{
		return;
	}
	for (int i = m_FirstUpdateComponentLocation; i < m_FirstUpdateComponentLocation + m_NumberUpdateComponents; i++)
	{
		std::shared_ptr<UpdateComponent> tempUpdateComponent = std::static_pointer_cast<UpdateComponent>(m_Components[i]);

		if (tempUpdateComponent->enabled())
		{
			tempUpdateComponent->update(delta);
		}
	}
}

void GameObject::draw(sf::RenderTarget& target)
{
	if (!m_isActive || !m_HasGraphicsComponent)
	{
		return;
	}
	if (m_Components[m_GraphicsComponentLocation]->enabled())
	{
		getGraphicsComponent()->draw(target, getTransformComponent());
	}
}

void GameObject::addComponent(std::shared_ptr<Component> component)
{
	m_Components.push_back(component);
	component->enable();

	if (component->getType() == "update")
	{
		m_HasUpdateComponent = true;
		m_NumberUpdateComponents++;

		if (m_NumberUpdateComponents == 1)
		{
			m_FirstUpdateComponentLocation = m_Components.size() - 1;
		}
	}
	else if (component->getType() == "graphics")
	{
		m_HasGraphicsComponent = true;
		m_GraphicsComponentLocation = m_Components.size() - 1;
	}
	else if (component->getType() == "transform")
	{
		m_TransformComponentLocation = m_Components.size() - 1;
	}
	else if (component->getType()         == "collider" &&
			 component->getSpecificType() == "rect")
	{
		m_HasCollider = true;
		m_NumberRectColliderComponents++;
		if (m_NumberRectColliderComponents == 1)
		{
			m_FirstRectColliderComponentLocation = m_Components.size() - 1;;
		}
	}
}

std::shared_ptr<Component> GameObject::getComponentByTypeAndSpecificType(std::string type, std::string specificType)
{
	for (auto& component : m_Components)
	{
		if (component->getType() == type && component->getSpecificType() == specificType)
		{
			return component;
		}
	}

	#ifdef _DEBUG
	std::cout << std::format("GameObject::getComponentByTypeAndSpecificType: COMPONENT NOT FOUND USING TYPE `{}` AND SPECIFIC TYPE `{}`", type, specificType);
	#endif // _DEBUG

	return m_Components[0];
}

void GameObject::start(GameObjectSharer* gameObjectSharer)
{
	for (auto& component : m_Components)
	{
		component->start(gameObjectSharer, this);
	}
}

void GameObject::setActive()
{
	m_isActive = true;
}

void GameObject::setInactive()
{
	m_isActive = false;
}

bool GameObject::isActive()
{
	return m_isActive;
}

std::string GameObject::getTag()
{
	return m_Tag;
}

void GameObject::setTag(std::string toTag)
{
	m_Tag = toTag;
}

sf::FloatRect& GameObject::getEncompassingRectCollider()
{
	if (!m_HasCollider)
	{
		return;
	}
	return std::static_pointer_cast<RectColliderComponent>(m_Components[m_FirstRectColliderComponentLocation])->getColliderRect();
}

bool GameObject::hasCollider()
{
	return m_HasCollider;
}

bool GameObject::hasUpdateComponent()
{
	return m_HasUpdateComponent;
}

std::string GameObject::getEncompassingRectColliderTag()
{
	if (!m_HasCollider)
	{
		return;
	}
	return std::static_pointer_cast<RectColliderComponent>(m_Components[m_FirstRectColliderComponentLocation])->getColliderTag();
}

std::shared_ptr<GraphicsComponent> GameObject::getGraphicsComponent()
{
	return std::static_pointer_cast<GraphicsComponent>(m_Components[m_GraphicsComponentLocation]);
}

std::shared_ptr<TransformComponent> GameObject::getTransformComponent()
{
	return std::static_pointer_cast<TransformComponent>(m_Components[m_TransformComponentLocation]);
}

std::shared_ptr<UpdateComponent> GameObject::getFirstUpdateComponent()
{
	return std::static_pointer_cast<UpdateComponent>(m_Components[m_FirstUpdateComponentLocation]);
}
