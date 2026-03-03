#pragma once
#include <vector>
#include "GameObject.h"
#include <string>

class GameObjectSharer
{
public:
	virtual std::vector<GameObject>& getGameObjectsWithGameObjectSharer() = 0;
	virtual GameObject& findFirstObjectWithTag(std::string tag) = 0;
};

