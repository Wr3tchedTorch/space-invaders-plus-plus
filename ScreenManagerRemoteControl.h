#pragma once

// #include "GameObject.h"
// #include "GameObjectSharer.h"

class ScreenManagerRemoteControl 
{
public:
	virtual void switchScreens(std::string toScreen) = 0;
	virtual void loadLevelInPlayMode(std::string screenToLoad) = 0;

	//virtual vector<GameObjects>& getGameObjects() = 0;

	// virtual GameObjectSharer& shareGameObjectSharer() = 0;
};