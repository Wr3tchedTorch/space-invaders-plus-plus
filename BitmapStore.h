#pragma once
#include <string>
#include <unordered_map>
#include <SFML/Graphics/Texture.hpp>

class BitmapStore
{
private:
	std::unordered_map<std::string, sf::Texture> m_Bitmaps;

	static BitmapStore* m_Instance;

public:
	static void createInstance();

	static sf::Texture& getTexture(const std::string& filepath);
	static void addTexture(const std::string& filepath);
};

