#include "LevelManager.h"
#include <string>
#include <vector>
#include "GameObject.h"
#include <iostream>
#include <format>
#include "PlayModeObjectLoader.h"

void LevelManager::runStartPhase()
{
    for (auto& gameObject : m_GameObjects)
    {
        gameObject.start(this);
    }

    activateAllGameObjects();
}

void LevelManager::activateAllGameObjects()
{
    for (auto& gameObject : m_GameObjects)
    {
        gameObject.setActive();
    }
}

std::vector<GameObject>& LevelManager::getGameObjects()
{
    return m_GameObjects;
}

void LevelManager::loadGameObjectsForPlayMode(std::string screenToLoad)
{
    m_GameObjects.clear();
    
    std::string filepath = std::format("{}/{}", WORLD_FOLDER, screenToLoad);

    PlayModeObjectLoader playModeObjectLoader {};
    playModeObjectLoader.loadGameObjectsForPlayMode(m_GameObjects, filepath);

    runStartPhase();
}

std::vector<GameObject>& LevelManager::getGameObjectsWithGameObjectSharer()
{
    return m_GameObjects;
}

GameObject& LevelManager::findFirstObjectWithTag(std::string tag)
{
    for (auto& gameObject : m_GameObjects)
    {
        if (gameObject.getTag() == tag)
        {
            return gameObject;
        }
    }

    #ifdef _DEBUG
    std::cout << std::format("LevelManager::findFirstObjectWithTag(): GameObject for tag `{}` not found!", tag);
    #endif // _DEBUG

    return m_GameObjects[0];
}
