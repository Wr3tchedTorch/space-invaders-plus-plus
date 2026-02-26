#include "SoundEngine.h"
#include <cassert>

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

void SoundEngine::playShoot()
{
	getInstance().m_ShootSound.play();
}

void SoundEngine::playInvaderExplosion()
{
	getInstance().m_InvaderExplosionSound.play();
}

void SoundEngine::playPlayerExplosion()
{
	getInstance().m_PlayerExplosionSound.play();
}

void SoundEngine::playClick()
{
	getInstance().m_ClickSound.play();
}
