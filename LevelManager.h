#pragma once
#include <vector>
#include "GameObject.h"
#include <string>
#include "GameObjectSharer.h"

class LevelManager : public GameObjectSharer
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

