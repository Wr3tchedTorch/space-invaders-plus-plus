#include "SelectInputHandler.h"
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "SoundEngine.h"
#include "WorldState.h"

void SelectInputHandler::handleKeyPressed(sf::Event& event, sf::RenderWindow& window)
{
	if (event.is<sf::Event::Closed>())
	{
		window.close();
	}
}

void SelectInputHandler::handleLeftMouseClick(const std::string& buttonInteractedWith, sf::RenderWindow& window)
{
	if (buttonInteractedWith == "Play")
	{
		SoundEngine::playClick();
		WorldState::WAVE_NUMBER = 0;
		getPointerToScreenManagerRemoteControl()->loadLevelInPlayMode("level1");
		return;
	}
	if (buttonInteractedWith == "Quit")
	{
		SoundEngine::playClick();
		window.close();
	}
}
