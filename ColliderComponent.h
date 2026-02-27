#pragma once
#include <string>
#include "Component.h"
#include "GameObjectSharer.h"
#include "GameObject.h"

class ColliderComponent : public Component
{
private:
	bool m_Enabled = false;
	std::string m_Type = "collider";

public:
	std::string getType() override;
	std::string getSpecificType() override;
	void enable() override;
	void disable() override;
	bool enabled() override;
	void start(GameObjectSharer* gameObjectSharer, GameObject* parent) override;
};

