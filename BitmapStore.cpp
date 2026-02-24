#include "BitmapStore.h"
#include <cassert>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <format>
#include <iostream>

BitmapStore* BitmapStore::m_Instance = nullptr;

void BitmapStore::createInstance()
{
	assert(m_Instance == nullptr);
	m_Instance = new BitmapStore();
}

sf::Texture& BitmapStore::getTexture(const std::string& filepath)
{
	auto& map = m_Instance->m_Bitmaps;
	auto  search = map.find(filepath);

	if (search == map.end())
	{
		#ifdef _DEBUG
		std::cout << std::format("BitmapStore::getTexture(const std::string& filepath): texture not found for filepath `{}`", filepath);
		#endif
	}
	return search->second;
}

void BitmapStore::addTexture(const std::string& filepath)
{
	auto& map    = m_Instance->m_Bitmaps;
	auto  search = map.find(filepath);

	if (search != map.end())
	{
		return;
	}
	auto& texture = map[filepath];

	if (!texture.loadFromFile(filepath))
	{
		#ifdef _DEBUG
		std::cout << std::format("BitmapStore::addTexture(const std::string& filepath): file not found: `{}`", filepath);
		#endif
	}
}
