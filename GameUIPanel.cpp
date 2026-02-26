#include "GameUIPanel.h"
#include <format>
#include <string>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>
#include "WorldState.h"
#include "UIPanel.h"

GameUIPanel::GameUIPanel(sf::Vector2u resolution) :
	UIPanel(
		resolution,
		{
			{ 1, 1 },
			{ resolution.x / 3, resolution.y / 12}
		},
		sf::Color(255, 255, 255, 50)
	)
{
	m_Text.setFillColor(sf::Color(0, 255, 0, 255));
	m_Text.setString("Score: 0 Lives: 3 Wave: 1");
	
	sf::Font font("fonts/Roboto-Bold.ttf");
	m_Text.setFont(font);
	m_Text.setPosition({ 15, 15 });
	m_Text.setCharacterSize(60);
}

void GameUIPanel::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	UIPanel::draw(target, states);

	target.draw(m_Text);
}

void GameUIPanel::updateText()
{
	std::string updatedText = std::format("Score: {} Lives: {} Wave: {}", WorldState::SCORE, WorldState::LIVES, WorldState::WAVE_NUMBER);
	m_Text.setString(updatedText);
}
