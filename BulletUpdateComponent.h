#pragma once
#include "UpdateComponent.h"
#include "TransformComponent.h"
#include <string>
#include <memory>
#include "RectColliderComponent.h"

class BulletUpdateComponent : public UpdateComponent
{
private:
	std::string m_SpecificType = "bullet";
	std::shared_ptr<TransformComponent>	   m_TransformComponent;
	std::shared_ptr<RectColliderComponent> m_RectColliderComponent;

	float m_Speed;

	int m_AlienBulletSpeedModifier;
	int m_ModifierRandomComponent = 5;
	int m_MinimumAdditionalModifier = 5;

	bool m_MovingUp = false;

public:
	bool m_BelongsToPlayer = false;
	bool m_IsSpawned = false;

	void spawnForPlayer(sf::Vector2f position);
	void spawnForInvader(sf::Vector2f position);
	void deSpawn();
	bool isMovingUp();

	std::string getSpecificType() override
	{
		return m_SpecificType;
	}

	void start(GameObjectSharer* gameObjectSharer, GameObject* parent) override
	{
		m_TransformComponent    = std::static_pointer_cast<TransformComponent>(parent->getComponentByTypeAndSpecificType("transform", "transform"));
		m_RectColliderComponent = std::static_pointer_cast<RectColliderComponent>(parent->getComponentByTypeAndSpecificType("collider", "rect"));
	}

	void update(float delta) override;
};

