#pragma once
#include "GraphicsComponent.h"
#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include <memory>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>

class StandardGraphicsComponent : public GraphicsComponent
{
private:
	sf::Sprite  m_Sprite;
	std::string m_SpecificType = "standard";

public:
	virtual std::string getSpecificType() override
	{
		return m_SpecificType;
	}

	void draw(sf::RenderTarget& target, std::shared_ptr<TransformComponent> transformComponent) override;
	void initializeGraphics(std::string bitmapName, sf::Vector2f objectSize) override;
};

