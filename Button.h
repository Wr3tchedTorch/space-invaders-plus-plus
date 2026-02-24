#pragma once
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>

class Button
{
private:
	sf::RectangleShape m_Background;
	sf::Font m_Font;

public:
	sf::Text m_Text;
	sf::FloatRect m_Collider;

	Button(sf::FloatRect bounds, sf::Color backgroundColor, std::string text);

	void draw(sf::RenderWindow& window);
};

