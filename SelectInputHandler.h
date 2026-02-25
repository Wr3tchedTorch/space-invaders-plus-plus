#pragma once
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "InputHandler.h"

class SelectInputHandler : public InputHandler
{
public:
	void handleKeyPressed(sf::Event& event, sf::RenderWindow& window) override;
	void handleLeftMouseClick(const std::string& buttonInteractedWith, sf::RenderWindow& window) override;
};

