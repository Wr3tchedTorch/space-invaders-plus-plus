#include "GameOverUIPanel.h"
#include "GameScreen.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>
#include "UIPanel.h"

void GameOverUIPanel::initializeButtons()
{
	addButton(
		{
			{m_ButtonPadding, m_ButtonPadding},
			{m_ButtonSize.x,  m_ButtonSize.y}
		},
		sf::Color(0, 255, 0, 255),
		"Play"
	);

	addButton(
		{
			{m_ButtonPadding, m_ButtonPadding * 2 + m_ButtonSize.y},
			{m_ButtonSize.x,  m_ButtonSize.y}
		},
		sf::Color(255, 0, 0, 255),
		"Home"
	);
}

GameOverUIPanel::GameOverUIPanel(sf::Vector2u resolution) :
	UIPanel(
		resolution,
		{
			{(resolution.x / 10.0f) * 3.0f, resolution.y / 2.0f},
			{(resolution.x / 10.0f) * 3.0f, resolution.y / 6.0f}
		},
		sf::Color(255, 255, 255, 50)
	)
{
	m_ButtonPadding = resolution.x / 100.0f;
	m_ButtonSize.x  = resolution.x / 20.0f;
	m_ButtonSize.y  = resolution.y / 20.0f;

	m_Text.setFillColor(sf::Color(0, 255, 0, 255));
	m_Text.setCharacterSize(160);
	
	sf::Font font("fonts/Roboto-Bold.ttf");
	m_Text.setFont(font);
	m_Text.setPosition({m_ButtonPadding, m_ButtonPadding * 2 + m_ButtonSize.y});

	initializeButtons();
}

void GameOverUIPanel::draw(sf::RenderTarget& target)
{
	if (GameScreen::m_GameOver)
	{
		show();
		UIPanel::draw(target);
		target.draw(m_Text);
	}
	else
	{
		hide();
	}
}