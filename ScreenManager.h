#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "BitmapStore.h"
#include "ScreenManagerRemoteControl.h"
#include "SelectScreen.h"
#include "GameScreen.h"
//#include "LevelManager.h"


class ScreenManager : public ScreenManagerRemoteControl
{
private:
	std::unordered_map<std::string, std::unique_ptr<Screen>> m_Screens;
	//LevelManager m_LevelManager;

protected:
	std::string m_CurrentScreen = "Select";

public:
	BitmapStore m_BitmapStore;
	
	ScreenManager(sf::Vector2u resolution);
	
	void handleInput(sf::RenderWindow& window);
	void update(float delta);
	void draw(sf::RenderWindow& window);

	void ScreenManagerRemoteControl::switchScreens(std::string toScreen)
	{
		m_CurrentScreen = toScreen;
		m_Screens[m_CurrentScreen].initialize();
	}

	void ScreenManagerRemoteControl::loadLevelInPlayMode(std::string screenToLoad)
	{
		//m_LevelManager.getGameObjects().clear();
		//m_LevelManager.loadGameObjectsForPlayMode(screenToLoad);
		switchScreens("Game");
	}

	//vector<GameObjects>& ScreenManagerRemoteControl::getGameObjects()
	//{
	//	return m_LevelManager.getGameObjects();
	//}

	//GameObjectSharer& ScreenManagerRemoteControl::shareGameObjectSharer()
	//{
	//	return m_LevelManager;
	//}
};

