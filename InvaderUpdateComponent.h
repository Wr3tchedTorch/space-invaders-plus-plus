#pragma once
#include "UpdateComponent.h"
#include <memory>
#include "TransformComponent.h"
#include "RectColliderComponent.h"

class InvaderUpdateComponent : public UpdateComponent
{
private:
	std::string m_SpecificType = "invader";

	std::shared_ptr<TransformComponent>    m_TransformComponent;
	std::shared_ptr<RectColliderComponent> m_RectColliderComponent;

	std::shared_ptr<TransformComponent>    m_PlayerTransformComponent;
	std::shared_ptr<RectColliderComponent> m_PlayerRectColliderComponent;

	BulletSpawner* m_BulletSpawner;

	float m_Speed = 10.0f;
	bool  m_MovingRight = false;
	float m_TimeSinceLastShot = 0.0f;
	float m_TimeBetweenShots  = 5.0f;
	float m_SpeedModifier	 = 0.05f;
	float m_AccuracyModifier;
	int m_RandSeed;

public:
	void dropDownAndReverse();
	bool isMovingRight();
	void initializeBulletSpawner(BulletSpawner bulletSpawner, int randSeed);

	std::string getSpecificType() override
	{
		return m_SpecificType;
	}

	void start(GameObjectSharer* gameObjectSharer, GameObject* parent) override
	{
		m_PlayerTransformComponent = std::static_pointer_cast<TransformComponent>(gameObjectSharer->findFirstObjectWithTag("Player")->getComponentByTypeAndSpecificType("transform", "transform"));
		m_PlayerRectColliderComponent = std::static_pointer_cast<RectColliderComponent>(gameObjectSharer->findFirstObjectWithTag("Player")->getComponentByTypeAndSpecificType("collider", "rect"));

		m_TransformComponent    = std::static_pointer_cast<TransformComponent>(gameObjectSharer->getComponentByTypeAndSpecificType("transform", "transform"));
		m_RectColliderComponent = std::static_pointer_cast<RectColliderComponent>(gameObjectSharer->getComponentByTypeAndSpecificType("collider", "rect"));
	}

	void update(float delta) override;
};

