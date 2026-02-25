#include "InputHandler.h"
#include <memory>
#include <string>
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Button.h"
#include "ScreenManagerRemoteControl.h"

void InputHandler::initializeHandler(Screen* parentScreen, sf::View* pointerToUIView, ScreenManagerRemoteControl* screenManagerRemoteControl, std::vector<std::shared_ptr<Button>> buttons)
{
	m_ParentScreen = parentScreen;
	m_PointerToUIPanelView = pointerToUIView;
	m_ScreenManagerRemoteControl = screenManagerRemoteControl;
	m_Buttons = buttons;
}

void InputHandler::handleInput(sf::Event& event, sf::RenderWindow& window)
{
	if (event.is<sf::Event::KeyPressed>())
	{
		handleKeyPressed(event, window);
		return;
	}

	if (event.is<sf::Event::KeyReleased>())
	{
		handleKeyReleased(event, window);
		return;
	}

	if (event.is<sf::Event::MouseButtonReleased>())
	{
		for (auto& button : m_Buttons)
		{
			sf::Vector2f clickPosition = window.mapPixelToCoords(sf::Mouse::getPosition(), *m_PointerToUIPanelView);
			if (button->m_Collider.contains(clickPosition))
			{
				handleLeftMouseClick(button->m_Text.getString().toAnsiString(), window);
				return;
			}
		}
	}

	handleGamepad();
}

void InputHandler::handleGamepad()
{
}

void InputHandler::handleKeyPressed(sf::Event& event, sf::RenderWindow& window)
{
}

void InputHandler::handleKeyReleased(sf::Event& event, sf::RenderWindow& window)
{
}

void InputHandler::handleLeftMouseClick(const std::string& buttonInteractedWith, sf::RenderWindow& window)
{
}

sf::View* InputHandler::getPointerToView()
{
	return m_PointerToUIPanelView;
}

Screen* InputHandler::getPointerToParentScreen()
{
	return m_ParentScreen;
}

ScreenManagerRemoteControl* InputHandler::getPointerToScreenManagerRemoteControl()
{
	return m_ScreenManagerRemoteControl;
}
