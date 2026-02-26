#pragma once
#include <memory>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Screen.h"
#include "ScreenManagerRemoteControl.h"
#include "GameInputHandler.h";

class GameScreen : public Screen
{
private:
	ScreenManagerRemoteControl* m_ScreenManagerRemoteControl;
	std::shared_ptr<GameInputHandler> m_GameInputHandler;

	sf::Texture m_BackgroundTexture;
	sf::Sprite  m_BackgroundSprite;

public:
	static bool m_GameOver;

	GameScreen(sf::Vector2u resolution, ScreenManagerRemoteControl* screenManagerRemoteControl, sf::Texture& backgroundTexture);
	
	void initialize() override;
	void update(float delta) override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

