#include "PlayModeObjectLoader.h"
#include <fstream>
#include "ObjectTags.h"
#include <string>
#include <vector>
#include "GameObject.h"
#include "GameObjectBlueprint.h"

void PlayModeObjectLoader::loadGameObjectsForPlayMode(std::vector<GameObject>& out, std::string filepath)
{
	std::ifstream inputFile(filepath);
	
	std::string currentLine;
	while (std::getline(inputFile, currentLine))
	{
		if (currentLine.find(ObjectTags::START_OF_OBJECT) != std::string::npos)
		{
			GameObjectBlueprint bp;
			m_BlueprintObjectParser.parseNextObjectForBlueprint(bp, inputFile);
			m_GameObjectFactoryPlaymode.buildGameObject(bp, out);
		}
	}
}
