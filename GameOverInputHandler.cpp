#include "GameOverInputHandler.h"
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "SoundEngine.h"
#include "WorldState.h"

void GameOverInputHandler::handleKeyPressed(sf::Event& event, sf::RenderWindow& window)
{
	if (auto keyPressed = event.getIf<sf::Event::KeyPressed>())
	{
		if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
		{
			getPointerToScreenManagerRemoteControl()->switchScreens("Select");
		}
	}
}

void GameOverInputHandler::handleLeftMouseClick(const std::string& buttonInteractedWith, sf::RenderWindow& window)
{
	if (buttonInteractedWith == "Play")
	{
		SoundEngine::playClick();
		WorldState::WAVE_NUMBER = 0;
		getPointerToScreenManagerRemoteControl()->loadLevelInPlayMode("level1");
		return;
	}
	if (buttonInteractedWith == "Home")
	{
		SoundEngine::playClick();
		getPointerToScreenManagerRemoteControl()->switchScreens("Select");
		return;
	}
}
