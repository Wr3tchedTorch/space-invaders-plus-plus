#pragma once
#include "InputHandler.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "PlayerUpdateComponent.h"
#include "TransformComponent.h"
#include <memory>

class GameInputHandler : public InputHandler
{
private:
	std::shared_ptr<PlayerUpdateComponent> m_PlayerUpdateComponent;
	std::shared_ptr<TransformComponent>	   m_PlayerTransformComponent;

	bool m_JoystickFirstButtonPressed = false;

public:
	void initialize();

	virtual void handleGamepad() override;
	virtual void handleKeyPressed(sf::Event& event, sf::RenderWindow& window) override;
	virtual void handleKeyReleased(sf::Event& event, sf::RenderWindow& window) override;
};

