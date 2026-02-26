#include "GameScreen.h"
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include "WorldState.h"
#include "Screen.h"
#include "ScreenManagerRemoteControl.h"
#include "GameInputHandler.h";
#include "GameOverInputHandler.h";
#include "GameUIPanel.h";
#include "GameOverUIPanel.h";

GameScreen::GameScreen(sf::Vector2u resolution, ScreenManagerRemoteControl* screenManagerRemoteControl, sf::Texture& backgroundTexture) :
	m_BackgroundTexture(backgroundTexture),
	m_BackgroundSprite(backgroundTexture)
{
	m_ScreenManagerRemoteControl = screenManagerRemoteControl;	

	m_GameInputHandler = std::make_shared<GameInputHandler>();
	auto gameUIPanel   = std::make_unique<GameUIPanel>();
	addPanel(gameUIPanel, m_GameInputHandler, m_ScreenManagerRemoteControl);

	auto gameOverInputHandler = std::make_shared<GameOverInputHandler>();
	auto gameOverUIPanel      = std::make_unique<GameOverUIPanel>();
	addPanel(gameOverUIPanel, gameOverInputHandler, m_ScreenManagerRemoteControl);

	float ratio = static_cast<float>(resolution.x) / resolution.y;
	
	WorldState::WORLD_HEIGHT = WorldState::WORLD_WIDTH / ratio;

	m_View.setSize({   WorldState::WORLD_WIDTH,   WorldState::WORLD_HEIGHT });
	m_View.setCenter({ WorldState::WORLD_WIDTH/2, WorldState::WORLD_HEIGHT/2 });

	m_BackgroundSprite.setScale(
		{
			m_View.getSize().x / m_BackgroundTexture.getSize().x,
			m_View.getSize().y / m_BackgroundTexture.getSize().y
		});
}

void GameScreen::initialize()
{
	m_GameInputHandler->initialize();

	WorldState::NUM_INVADERS = 0;

	if (WorldState::WAVE_NUMBER == 0)
	{
		WorldState::NUM_INVADERS_AT_START = WorldState::NUM_INVADERS;
		WorldState::WAVE_NUMBER = 1;
		WorldState::LIVES = 3;
		WorldState::SCORE = 0;
	}
}

void GameScreen::update(float delta)
{
	Screen::update(delta);

	if (m_GameOver)
	{
		return;
	}

	if (WorldState::LIVES <= 0)
	{
		m_GameOver = true;
		return;
	}

	if (WorldState::NUM_INVADERS <= 0)
	{
		WorldState::WAVE_NUMBER++;
		m_ScreenManagerRemoteControl->loadLevelInPlayMode("level1");
	}
}

void GameScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.setView(m_View);
	target.draw(m_BackgroundSprite);

	Screen::draw(target, states);
}
