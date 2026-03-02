#pragma once
#include <vector>
#include "GameObject.h"

class GameObjectSharer
{
public:
	virtual std::vector<GameObject>& getGameObjectsWithGameObjectSharer() = 0;
	virtual GameObject& findFirstGameObjectWithTag() = 0;
};

