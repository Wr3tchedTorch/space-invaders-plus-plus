#pragma once
#include "BlueprintObjectParser.h"
#include "GameObject.h"
#include <string>
#include <vector>
#include "GameObjectFactoryPlayMode.h"

class PlayModeObjectLoader
{
private:
	BlueprintObjectParser m_BlueprintObjectParser;
	GameObjectFactoryPlayMode m_GameObjectFactoryPlaymode;

public:
	void loadGameObjectsForPlayMode(std::vector<GameObject>& out, std::string filepath);
};

