#pragma once
#include "InputHandler.h"

class GameInputHandler : public InputHandler
{
public:
	void initialize();

	virtual void handleGamepad() override;
	virtual void handleKeyPressed(sf::Event& event, sf::RenderWindow& window) override;
	virtual void handleKeyReleased(sf::Event& event, sf::RenderWindow& window) override;
};

