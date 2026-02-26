#pragma once
#include "UIPanel.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>

class GameOverUIPanel : public UIPanel
{
private:
	void initializeButtons();

public:
	GameOverUIPanel(sf::Vector2u resolution);

	void draw(sf::RenderTarget& target) override;
};

