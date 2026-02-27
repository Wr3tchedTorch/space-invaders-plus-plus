#pragma once
#include "ColliderComponent.h"
#include <SFML/Graphics/Rect.hpp>
#include <string>

class RectColliderComponent : public ColliderComponent
{
private:
	std::string   m_Tag;
	std::string   m_SpecificType = "rect";
	sf::FloatRect m_CollisionRect;

public:
	RectColliderComponent(std::string tag);

	std::string getColliderTag();

	void setColliderRect(sf::FloatRect rect);
	const sf::FloatRect& getColliderRect();

	std::string getSpecificType() override
	{
		return m_SpecificType;
	}

	void start(GameObjectSharer* gameObjectSharer, GameObject* parent) override
	{
	}
};

