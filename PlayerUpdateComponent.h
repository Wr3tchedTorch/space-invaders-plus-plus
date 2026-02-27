#pragma once
#include "UpdateComponent.h"
#include <string>
#include "TransformComponent.h"
#include <memory>
#include "RectColliderComponent.h"
#include <SFML/System/Vector2.hpp>

class PlayerUpdateComponent : public UpdateComponent
{
private:
	std::string m_SpecificType = "player";

	float m_Speed   = 50.0f;
	float m_ExtendX = 0.0f;
	float m_ExtendY = 0.0f;

	bool m_IsHoldingRight = false;
	bool m_IsHoldingLeft  = false;
	bool m_IsHoldingDown  = false;
	bool m_IsHoldingUp    = false;

	std::shared_ptr<TransformComponent>	   m_TransformComponent;
	std::shared_ptr<RectColliderComponent> m_RectColliderComponent;

public:
	void updateShipTravelWithController(sf::Vector2f direction);
	void moveRight();
	void moveLeft();
	void moveDown();
	void moveUp();

	void stopRight();
	void stopLeft();
	void stopDown();
	void stopUp();

	std::string getSpecificType() override
	{
		return m_SpecificType;
	}

	void start(GameObjectSharer* gameObjectSharer, GameObject* parent) override
	{
		m_TransformComponent    = static_pointer_cast<TransformComponent>(parent->getComponentByTypeAndSpecificType("transform", "transform"));
		m_RectColliderComponent = static_pointer_cast<RectColliderComponent>(parent->getComponentByTypeAndSpecificType("collider", "rect"));
	}

	void update(float delta) override;
};

