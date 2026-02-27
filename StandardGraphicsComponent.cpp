#include "StandardGraphicsComponent.h"
#include <memory>
#include <string>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>
#include "BitmapStore.h"
#include <format>
#include <SFML/Graphics/Color.hpp>

void StandardGraphicsComponent::draw(sf::RenderTarget& target, std::shared_ptr<TransformComponent> transformComponent)
{
	m_Sprite.setPosition(transformComponent->getLocation());
	target.draw(m_Sprite);
}

void StandardGraphicsComponent::initializeGraphics(std::string bitmapName, sf::Vector2f objectSize)
{
	std::string texturePath = std::format("graphics/{}.png", bitmapName);
	BitmapStore::addTexture(texturePath);
	m_Sprite.setTexture(BitmapStore::getTexture(texturePath));

	sf::Vector2f textureSize(m_Sprite.getTexture().getSize());
	m_Sprite.setScale({ objectSize.x / textureSize.x, objectSize.y / textureSize.y });
	m_Sprite.setColor(sf::Color(255, 255, 255));
}
