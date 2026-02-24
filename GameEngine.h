#pragma once
//#include "ScreenManager.h"
//#include "SoundEngine.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>

class GameEngine
{
private:
	sf::RenderWindow m_Window;
	sf::Vector2f	 m_Resolution;

	sf::Clock m_Clock;
	sf::Time  m_DeltaTime;
	float m_FPS = 0;

	std::unique_ptr<ScreenManager> m_ScreenManager;

	void handleInput();
	void update();
	void draw();

public:
	SoundEngine m_SoundEngine;

	GameEngine();
	void run();
};

