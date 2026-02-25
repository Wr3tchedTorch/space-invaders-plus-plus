#pragma once
#include <vector>
#include <memory>
#include <string>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Button.h"

class UIPanel : public sf::Drawable
{
private:
	std::vector<std::shared_ptr<Button>> m_Buttons;
	
	sf::RectangleShape m_Background;
	bool m_Hidden = false;	

protected:
	sf::Vector2f m_ButtonSize;
	float m_ButtonPadding = 0;

	sf::Text m_Text;
	sf::Font m_Font;

	void addButton(sf::FloatRect bounds, sf::Color color, std::string text);

public:
	sf::View m_View;

	UIPanel(sf::Vector2u resolution, sf::FloatRect bounds, sf::Color color);

	std::vector<std::shared_ptr<Button>> getButtons();
	
	void show();
	void hide();	

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

