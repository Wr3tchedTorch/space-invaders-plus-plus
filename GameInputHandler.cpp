#include "GameInputHandler.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

void GameInputHandler::initialize()
{
}

void GameInputHandler::handleGamepad()
{
}

void GameInputHandler::handleKeyPressed(sf::Event& event, sf::RenderWindow& window)
{
	if (auto keyPressed = event.getIf<sf::Event::KeyPressed>())
	{
		if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
		{
			getPointerToScreenManagerRemoteControl()->switchScreens("Select");
		}
	}
}

void GameInputHandler::handleKeyReleased(sf::Event& event, sf::RenderWindow& window)
{
}
