#pragma once
#include "BlueprintObjectParser.h"
#include "GameObject.h"
#include <string>
#include <vector>
class PlayModeObjectLoader
{
public:
	BlueprintObjectParser m_BlueprintObjectParser;
	GameObjectFactoryPlaymode m_GameObjectFactoryPlaymode;

private:
	void loadGameObjectsForPlayMode(std::vector<GameObject>& out, std::string filepath);
};

