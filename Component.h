#pragma once
#include <string>
#include "GameObject.h"
#include "GameObjectSharer.h"

class Component
{
public:
	virtual std::string getType() = 0;
	virtual std::string getSpecificType() = 0;
	virtual void enable()  = 0;
	virtual void disable() = 0;
	virtual bool enabled() = 0;
	virtual void start(GameObjectSharer* gameObjectSharer, GameObject* parent) = 0;
};

