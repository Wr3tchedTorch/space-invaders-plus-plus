#pragma once
#include "Component.h"
#include <string>

class UpdateComponent : public Component
{
private:
	std::string m_Type = "update";
	bool m_Enabled = false;

public:
	virtual void update(float delta) = 0;

	std::string getType() override;
	std::string getSpecificType() override;
	void enable() override;
	void disable() override;
	bool enabled() override;
	void start(GameObjectSharer* gameObjectSharer, GameObject* parent) override;
};

