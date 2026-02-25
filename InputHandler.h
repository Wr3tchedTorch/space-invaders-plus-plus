#pragma once
#include <memory>
#include <vector>
#include <string>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "ScreenManagerRemoteControl.h"
#include "Button.h"

class Screen;

class InputHandler
{
private:
	Screen*	  m_ParentScreen;
	sf::View* m_PointerToUIPanelView;
	ScreenManagerRemoteControl* m_ScreenManagerRemoteControl;

	std::vector<std::shared_ptr<Button>> m_Buttons;

public:
	void initializeHandler(
		Screen*	  parentScreen,
		sf::View* pointerToUIView,
		ScreenManagerRemoteControl* screenManagerRemoteControl,
		std::vector<std::shared_ptr<Button>> buttons
	);

	void handleInput(sf::Event& event, sf::RenderWindow& window);
	virtual void handleGamepad();
	virtual void handleKeyPressed(sf::Event& event, sf::RenderWindow& window);
	virtual void handleKeyReleased(sf::Event& event, sf::RenderWindow& window);
	virtual void handleLeftMouseClick(const std::string& buttonInteractedWith, sf::RenderWindow& window);

	sf::View* getPointerToView();
	Screen* getPointerToParentScreen();

	ScreenManagerRemoteControl* getPointerToScreenManagerRemoteControl();
};

