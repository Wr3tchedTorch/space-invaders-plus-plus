#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include "InputHandler.h"
#include "UIPanel.h"
#include "ScreenManagerRemoteControl.h"

class Screen
{
private:
	std::vector<std::shared_ptr<InputHandler>> m_InputHandlers;
	std::vector<std::unique_ptr<UIPanel>> m_UIPanels;

protected:
	void addPanel(
		std::unique_ptr<UIPanel> panel, 
		std::shared_ptr<InputHandler> inputHandler, 
		ScreenManagerRemoteControl* screenManagerRemoteControl
	);

public:
	sf::View m_View;

	virtual void initialize();
	
	virtual void update(float delta);
	virtual void draw(sf::RenderTarget& target);
	virtual void handleInput(sf::RenderWindow& window);
};

