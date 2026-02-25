#include "ScreenManager.h"
#include <SFML/System/Vector2.hpp>

ScreenManager::ScreenManager(sf::Vector2u resolution)
{
	m_Screens["Game"]   = std::unique_ptr<GameScreen>(new GameScreen(this, resolution));
	m_Screens["Select"] = std::unique_ptr<SelectScreen>(new SelectScreen(this, resolution));
}

void ScreenManager::handleInput(sf::RenderWindow& window)
{
	m_Screens[m_CurrentScreen]->handleInput(window);
}

void ScreenManager::update(float delta)
{
	m_Screens[m_CurrentScreen]->update(delta);
}

void ScreenManager::draw(sf::RenderWindow& window)
{
	m_Screens[m_CurrentScreen]->draw(window);
}
