#include "GameInputHandler.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "SoundEngine.h"
#include <SFML/System/Vector2.hpp>
#include "GameScreen.h"

void GameInputHandler::initialize()
{
}

void GameInputHandler::handleGamepad()
{
	float deadZone = 10.0f;

	float x = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X);
	float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y);

	if (x > -deadZone && x < deadZone)
	{
		x = 0;
	}
	if (y > -deadZone && y < deadZone)
	{
		y = 0;
	}

	m_PlayerUpdateComponent->updateShipTravelWithController({ x, y });

	if (sf::Joystick::isButtonPressed(0, 1))
	{
		m_JoystickFirstButtonPressed = true;
	}
	else if (m_JoystickFirstButtonPressed)
	{
		m_JoystickFirstButtonPressed = false;

		SoundEngine::playShoot();
		sf::Vector2f spawnLocation = m_PlayerTransformComponent->getLocation();
		spawnLocation.x += m_PlayerTransformComponent->getSize().x / 2;

		static_cast<GameScreen*>(getPointerToParentScreen())->spawnBullet(spawnLocation, true);
	}
}

void GameInputHandler::handleKeyPressed(sf::Event& event, sf::RenderWindow& window)
{
	if (auto keyPressed = event.getIf<sf::Event::KeyPressed>())
	{
		if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
		{
			getPointerToScreenManagerRemoteControl()->switchScreens("Select");
		}
		else if (keyPressed->scancode == sf::Keyboard::Scancode::Left)
		{
			m_PlayerUpdateComponent->moveLeft();
		}
		else if (keyPressed->scancode == sf::Keyboard::Scancode::Right)
		{
			m_PlayerUpdateComponent->moveRight();
		}
		else if (keyPressed->scancode == sf::Keyboard::Scancode::Up)
		{
			m_PlayerUpdateComponent->moveUp();
		}
		else if (keyPressed->scancode == sf::Keyboard::Scancode::Down)
		{
			m_PlayerUpdateComponent->moveDown();
		}
	}
}

void GameInputHandler::handleKeyReleased(sf::Event& event, sf::RenderWindow& window)
{
	if (auto keyReleased = event.getIf<sf::Event::KeyReleased>())
	{
		if (keyReleased->scancode == sf::Keyboard::Scancode::Left)
		{
			m_PlayerUpdateComponent->stopLeft();
		}
		else if (keyReleased->scancode == sf::Keyboard::Scancode::Right)
		{
			m_PlayerUpdateComponent->stopRight();
		}
		else if (keyReleased->scancode == sf::Keyboard::Scancode::Up)
		{
			m_PlayerUpdateComponent->stopUp();
		}
		else if (keyReleased->scancode == sf::Keyboard::Scancode::Down)
		{
			m_PlayerUpdateComponent->stopDown();
		}
		else if (keyReleased->scancode == sf::Keyboard::Scancode::Space)
		{
			SoundEngine::playShoot();
			sf::Vector2f spawnLocation = m_PlayerTransformComponent->getLocation();
			spawnLocation.x += m_PlayerTransformComponent->getSize().x / 2;

			static_cast<GameScreen*>(getPointerToParentScreen())->spawnBullet(spawnLocation, true);
		}
	}
}
