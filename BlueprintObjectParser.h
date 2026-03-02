#pragma once
#include <string>
#include <fstream>
#include "GameObjectBlueprint.h"

class BlueprintObjectParser
{
private:
	std::string extractStringBetweenTags(std::string line, std::string startTag, std::string endTag);

public:
	void parseNextObjectForBlueprint(GameObjectBlueprint& out, std::ifstream& inputFile);
};

