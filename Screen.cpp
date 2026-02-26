#include "Screen.h"
#include <memory>
#include <utility>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "InputHandler.h"
#include "ScreenManagerRemoteControl.h"
#include "UIPanel.h"

void Screen::addPanel(std::unique_ptr<UIPanel> panel, std::shared_ptr<InputHandler> inputHandler, ScreenManagerRemoteControl* screenManagerRemoteControl)
{
	inputHandler->initializeHandler(this, &panel->m_View, screenManagerRemoteControl, panel->getButtons());

	m_UIPanels.push_back(std::move(panel));
	m_InputHandlers.push_back(inputHandler);
}

void Screen::initialize()
{
}

void Screen::update(float delta)
{
}

void Screen::draw(sf::RenderTarget& target)
{	
	for (auto& panel : m_UIPanels)
	{
		panel->draw(target);
	}
}

void Screen::handleInput(sf::RenderWindow& window)
{
	while (auto event = window.pollEvent())
	{
		for (auto& inputHandler : m_InputHandlers)
		{
			inputHandler->handleInput(*event, window);
		}
	}
}
