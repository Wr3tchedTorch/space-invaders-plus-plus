#pragma once
#include "Component.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <string>
#include <SFML/System/Vector2.hpp>
#include "TransformComponent.g"

class GraphicsComponent : public Component
{
	std::string m_Type = "graphics";
	bool m_Enabled = false;

public:
	virtual void draw(sf::RenderTarget& target, std::shared_ptr<TransformComponent> transformComponent) = 0;
	virtual void initializeGraphics(std::string bitmapName, sf::Vector2f objectSize) = 0;

	std::string getType() override;
	std::string getSpecificType() override;
	void enable() override;
	void disable() override;
	bool enabled() override;
	void start(GameObjectSharer* gameObjectSharer, GameObject* parent) override;
};

