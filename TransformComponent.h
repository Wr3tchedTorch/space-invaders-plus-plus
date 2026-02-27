#pragma once
#include "Component.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <string>

class TransformComponent : public Component
{
private:
	sf::FloatRect m_Bounds;
	std::string   m_Type = "transform";

public:
	TransformComponent(sf::FloatRect bounds);

	sf::Vector2f& getSize();
	sf::Vector2f& getLocation();

	std::string getType() override;
	std::string getSpecificType() override;

	void enable() override
	{
	}

	void disable() override
	{
	}

	bool enabled() override
	{
		return false;
	}

	void start(GameObjectSharer* gameObjectSharer, GameObject* parent) override
	{
	}
};

