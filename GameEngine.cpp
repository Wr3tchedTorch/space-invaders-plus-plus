#include "GameEngine.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowEnums.hpp>
#include <memory>

GameEngine::GameEngine()
{
	sf::VideoMode desktopVideoMode = sf::VideoMode::getDesktopMode();

	m_Resolution = sf::Vector2f(desktopVideoMode.size);
	m_Window.create(desktopVideoMode, "Space Invaders++ by Eric", sf::State::Fullscreen);

	m_ScreenManager = std::unique_ptr<ScreenManager>(new ScreenManager(sf::Vector2i(m_Resolution)));
}

void GameEngine::run()
{
	while (m_Window.isOpen())
	{
		m_DeltaTime = m_Clock.restart();
		m_Delta = m_DeltaTime.asSeconds();
		
		handleInput();
		update();
		draw();
	}
}

void GameEngine::handleInput()
{
	m_ScreenManager->handleInput(m_Window);
}

void GameEngine::update()
{
	m_ScreenManager->update(m_Delta);
}

void GameEngine::draw()
{
	m_Window.clear(sf::Color::Black);
	m_ScreenManager->draw(m_Window);
	m_Window.display();
}