#include "SelectScreen.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <utility>
#include "ScreenManagerRemoteControl.h"
#include "Screen.h"

SelectScreen::SelectScreen(ScreenManagerRemoteControl* screenManagerRemoteControl, sf::Vector2u resolution, sf::Texture& backgroundTexture) :
	m_BackgroundTexture(backgroundTexture),
	m_BackgroundSprite(backgroundTexture)
{
	auto selectUIPanel	    = std::make_unique<SelectUIPanel>(resolution);
	auto selectInputHandler = std::make_shared<SelectInputHandler>();

	addPanel(std::move(selectUIPanel), selectInputHandler, screenManagerRemoteControl);

	m_ScreenManagerRemoteControl = screenManagerRemoteControl;

	sf::Vector2u textureSize = m_BackgroundTexture.getSize();
	m_BackgroundSprite.setScale({ m_View.getSize().x / textureSize.x, m_View.getSize().y / textureSize.y });
}

void SelectScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.setView(m_View);
	target.draw(m_BackgroundSprite);
	
	Screen::draw(target, states);	
}
