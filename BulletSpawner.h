#pragma once
#include <SFML/System/Vector2.hpp>

class BulletSpawner
{
public:
	virtual void spawnBullet(sf::Vector2f startPosition, bool forPlayer) = 0;
};

