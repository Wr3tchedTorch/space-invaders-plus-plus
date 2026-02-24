#include "Button.h"
#include <string>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

Button::Button(sf::FloatRect bounds, sf::Color backgroundColor, std::string text) :
	m_Font("fonts/Roboto-Bold.ttf"),
	m_Text(m_Font, text)
{
	m_Background.setFillColor(backgroundColor);
	m_Background.setPosition(bounds.position);
	m_Background.setSize(bounds.size);

	sf::Vector2f padding({ bounds.size.x / 10, bounds.size.y / 10 });
	m_Text.setCharacterSize(bounds.size.y * .7f);
	m_Text.setPosition({ bounds.position.x + padding.x, bounds.position.y + padding.y });

	m_Collider = bounds;
}
