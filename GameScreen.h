#pragma once
#include <memory>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Screen.h"
#include "ScreenManagerRemoteControl.h"
#include "GameInputHandler.h"
#include "BulletSpawner.h"
#include <vector>
#include <SFML/System/Clock.hpp>

class GameScreen : public Screen, public BulletSpawner
{
private:
	ScreenManagerRemoteControl* m_ScreenManagerRemoteControl;
	std::shared_ptr<GameInputHandler> m_GameInputHandler;

	sf::Texture m_BackgroundTexture;
	sf::Sprite  m_BackgroundSprite;

	std::vector<int> m_BulletObjectPositions;
	bool m_WaitingToSpawnBulletForPlayer  = false;
	bool m_WaitingToSpawnBulletForInvader = false;
	sf::Vector2f m_PlayerBulletSpawnLocation;
	sf::Vector2f m_InvaderBulletSpawnLocation;

	int m_NextBullet = 0;
	int m_NumberInvadersInWorldFile = 0;

	sf::Clock m_BulletClock;

public:
	static bool m_GameOver;

	GameScreen(sf::Vector2u resolution, ScreenManagerRemoteControl* screenManagerRemoteControl, sf::Texture& backgroundTexture);
	
	void initialize() override;
	void update(float delta) override;
	void draw(sf::RenderTarget& target) override;

	BulletSpawner* getBulletSpawner();
	void spawnBullet(sf::Vector2f startPosition, bool forPlayer) override;
};

