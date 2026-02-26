#pragma once
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "InputHandler.h"

class GameOverInputHandler : public InputHandler
{

public:
	virtual void handleKeyPressed(sf::Event& event, sf::RenderWindow& window);
	virtual void handleLeftMouseClick(const std::string& buttonInteractedWith, sf::RenderWindow& window);
};

