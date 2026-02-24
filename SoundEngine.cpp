#include "SoundEngine.h"
#include <cassert>

SoundEngine* SoundEngine::m_Instance = nullptr;

SoundEngine::SoundEngine() :
	m_ShootBuffer("sounds/shoot.wav"),
	m_InvaderExplosionBuffer("sounds/click.wav"),
	m_PlayerExplosionBuffer("sounds/click.wav"),
	m_ClickBuffer("sounds/click.wav"),

	m_ShootSound(m_ShootBuffer),
	m_ClickSound(m_ClickBuffer),
	m_InvaderExplosionSound(m_InvaderExplosionBuffer),
	m_PlayerExplosionSound(m_PlayerExplosionBuffer)
{
}

void SoundEngine::createInstance()
{
	assert(m_Instance == nullptr);

	m_Instance = new SoundEngine();
}

void SoundEngine::playShoot()
{
	m_Instance->m_ShootSound.play();
}

void SoundEngine::playInvaderExplosion()
{
	m_Instance->m_InvaderExplosionSound.play();
}

void SoundEngine::playPlayerExplosion()
{
	m_Instance->m_PlayerExplosionSound.play();
}

void SoundEngine::playClick()
{
	m_Instance->m_ClickSound.play();
}
