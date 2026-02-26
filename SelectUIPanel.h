#pragma once
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>
#include "UIPanel.h"

class SelectUIPanel : public UIPanel
{
private:
	void initializeButtons();

public:
	SelectUIPanel(sf::Vector2u resolution);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

