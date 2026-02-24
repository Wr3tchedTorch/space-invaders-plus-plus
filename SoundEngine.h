#pragma once
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

class SoundEngine
{
private:
	sf::SoundBuffer m_ShootBuffer;
	sf::SoundBuffer m_InvaderExplosionBuffer;
	sf::SoundBuffer m_PlayerExplosionBuffer;
	sf::SoundBuffer m_ClickBuffer;

	sf::Sound m_ShootSound;
	sf::Sound m_InvaderExplosionSound;
	sf::Sound m_PlayerExplosionSound;
	sf::Sound m_ClickSound;

	static SoundEngine* m_Instance;
	
	SoundEngine();
public:

	static void createInstance();

	static void playShoot();
	static void playInvaderExplosion();
	static void playPlayerExplosion();
	static void playClick();
};

