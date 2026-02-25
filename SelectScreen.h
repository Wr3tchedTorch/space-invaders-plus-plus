#pragma once
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "ScreenManagerRemoteControl.h"
#include "Screen.h"

class SelectScreen : public Screen
{
private:
	ScreenManagerRemoteControl* m_ScreenManagerRemoteControl = nullptr;
	sf::Texture& m_BackgroundTexture;
	sf::Sprite   m_BackgroundSprite;

public:
	SelectScreen(ScreenManagerRemoteControl* screenManagerRemoteControl, sf::Vector2u resolution, sf::Texture& backgroundTexture);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

