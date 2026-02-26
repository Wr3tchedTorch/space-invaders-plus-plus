#pragma once
#include "UIPanel.h"
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>

class GameUIPanel : public UIPanel
{
public:
	GameUIPanel(sf::Vector2u resolution);
	
	void draw(sf::RenderTarget& target) override;
};

