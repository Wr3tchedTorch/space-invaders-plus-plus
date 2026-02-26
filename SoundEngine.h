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

	SoundEngine();

	SoundEngine(const SoundEngine&) = delete;
	void operator=(const SoundEngine&) = delete;

	static SoundEngine& getInstance() {
		static SoundEngine instance;
		return instance;
	};
public:

	static void playShoot();
	static void playInvaderExplosion();
	static void playPlayerExplosion();
	static void playClick();
};

