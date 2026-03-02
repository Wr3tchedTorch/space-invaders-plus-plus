#pragma once
#include <vector>
#include "GameObject.h"

#include "GameObjectBlueprint.h"

class GameObjectFactoryPlayMode
{
public:
	void buildGameObject(GameObjectBlueprint& gameObjectBlueprint, std::vector<GameObject>& gameObjects);
};

