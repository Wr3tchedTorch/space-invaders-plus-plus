#pragma once
#include <vector>
#include "GameObject.h"
#include <string>

class LevelManager : GameObjectSharer
{
private:
	std::vector<GameObject> m_GameObjects;
	const std::string WORLD_FOLDER = "world";

	void runStartPhase();
	void activateAllGameObjects();

public:
	std::vector<GameObject>& getGameObjects();
	void loadGameObjectsForPlayMode(std::string screenToLoad);

	std::vector<GameObject>& getGameObjectsWithGameObjectSharer() override;

	GameObject& findFirstObjectWithTag(std::string tag) override;

};

