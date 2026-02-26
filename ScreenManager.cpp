#include "ScreenManager.h"
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include "BitmapStore.h"
#include "GameScreen.h"
#include "SelectScreen.h"

ScreenManager::ScreenManager(sf::Vector2u resolution)
{
	BitmapStore::addTexture("graphics/background.png");

	m_Screens["Game"]   = std::unique_ptr<GameScreen>(new GameScreen(resolution, this, BitmapStore::getTexture("graphics/background.png")));
	m_Screens["Select"] = std::unique_ptr<SelectScreen>(new SelectScreen(this, resolution, BitmapStore::getTexture("graphics/background.png")));
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
