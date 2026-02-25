#include "UIPanel.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <string>
#include <memory>
#include <vector>
#include "Button.h"

void UIPanel::addButton(sf::FloatRect bounds, sf::Color color, std::string text)
{
	m_Buttons.push_back(std::make_unique<Button>(bounds, color, text));
}

UIPanel::UIPanel(sf::Vector2u resolution, sf::FloatRect bounds, sf::Color color) : m_Text(m_Font, "")
{
	m_Background.setSize(bounds.size);
	m_Background.setPosition(bounds.position);
	m_Background.setFillColor(color);

	m_View.setSize(bounds.size);
	m_View.setCenter({ bounds.size.x / 2, bounds.size.x / 2 });

	float viewportStartX = bounds.position.x / resolution.x;
	float viewportStartY = bounds.position.y / resolution.y;
	float viewportSizeX  = bounds.size.x	 / resolution.x;
	float viewportSizeY  = bounds.size.y	 / resolution.y;

	m_View.setViewport({ {viewportStartX, viewportStartY}, {viewportSizeX, viewportSizeY} });
}

std::vector<std::shared_ptr<Button>> UIPanel::getButtons()
{
	return m_Buttons;
}

void UIPanel::show()
{
	m_Hidden = false;
}

void UIPanel::hide()
{
	m_Hidden = true;
}

void UIPanel::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (m_Hidden)
	{
		return;
	}
	target.setView(m_View);
	target.draw(m_Background);
	for (const auto& button : m_Buttons)
	{
		target.draw(*button);
	}
}
