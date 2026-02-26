#include "SelectUIPanel.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Font.hpp>
#include "UIPanel.h"

void SelectUIPanel::initializeButtons()
{
	addButton(
		{
			{ m_ButtonPadding, m_ButtonPadding },
			{ m_ButtonSize.x,  m_ButtonSize.y  }
		},
		sf::Color(0, 255, 0, 255),
		"Play"
	);

	addButton(
		{
			{ m_ButtonSize.x + m_ButtonPadding * 2, m_ButtonPadding },
			{ m_ButtonSize.x,  m_ButtonSize.y  }
		},
		sf::Color(255, 0, 0, 255),
		"Quit"
	);
}

SelectUIPanel::SelectUIPanel(sf::Vector2u resolution) :
	UIPanel(
		resolution,
		{
			{ (resolution.x / 10) * 2, resolution.y / 3 },
			{ (resolution.x / 10) * 6, resolution.y / 3 }
		},
		sf::Color(255, 255, 255, 50)
	)
{
	m_ButtonPadding = resolution.x / 100.0f;
	m_ButtonSize.x  = resolution.x / 20.0f;
	m_ButtonSize.y  = resolution.y / 20.0f;

	sf::Font font("fonts/Roboto-Bold.ttf");

	m_Text.setFont(font);
	m_Text.setString("Space Invaders ++");
	m_Text.setFillColor(sf::Color(255, 0, 0, 255));
	m_Text.setCharacterSize(160);
	m_Text.setPosition({m_ButtonPadding, m_ButtonSize.y + m_ButtonPadding * 2});

	initializeButtons();
}

void SelectUIPanel::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	UIPanel::draw(target, states);	
	target.draw(m_Text);
}
