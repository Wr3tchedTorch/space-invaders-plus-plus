#include "BlueprintObjectParser.h"
#include <fstream>
#include "GameObjectBlueprint.h"
#include <string>
#include "ObjectTags.h"

std::string BlueprintObjectParser::extractStringBetweenTags(std::string line, std::string startTag, std::string endTag)
{
	int start = startTag.size();
	int count = line.size() - startTag.size() - endTag.size();

	return line.substr(start, count);	
}

void BlueprintObjectParser::parseNextObjectForBlueprint(GameObjectBlueprint& out, std::ifstream& inputFile)
{
	std::string currentLine;
	
	std::string value = "";
	while (std::getline(inputFile, currentLine))
	{
		if (currentLine.find(ObjectTags::COMPONENT) != std::string::npos)
		{
			value = extractStringBetweenTags(currentLine, ObjectTags::COMPONENT, ObjectTags::COMPONENT_END);

			out.addToComponentList(value);
		}
		else if (currentLine.find(ObjectTags::NAME) != std::string::npos)
		{
			value = extractStringBetweenTags(currentLine, ObjectTags::NAME, ObjectTags::NAME_END);

			out.setName(value);
		}
		else if (currentLine.find(ObjectTags::WIDTH) != std::string::npos)
		{
			value = extractStringBetweenTags(currentLine, ObjectTags::WIDTH, ObjectTags::WIDTH_END);

			out.setWidth(std::stof(value));
		}
		else if (currentLine.find(ObjectTags::HEIGHT) != std::string::npos)
		{
			value = extractStringBetweenTags(currentLine, ObjectTags::HEIGHT, ObjectTags::HEIGHT_END);

			out.setHeight(std::stof(value));
		}
		else if (currentLine.find(ObjectTags::LOCATION_X) != std::string::npos)
		{
			value = extractStringBetweenTags(currentLine, ObjectTags::LOCATION_X, ObjectTags::LOCATION_X_END);

			out.setLocationX(std::stof(value));
		}
		else if (currentLine.find(ObjectTags::LOCATION_Y) != std::string::npos)
		{
			value = extractStringBetweenTags(currentLine, ObjectTags::LOCATION_Y, ObjectTags::LOCATION_Y_END);

			out.setLocationY(std::stof(value));
		}
		else if (currentLine.find(ObjectTags::BITMAP_NAME) != std::string::npos)
		{
			value = extractStringBetweenTags(currentLine, ObjectTags::BITMAP_NAME, ObjectTags::BITMAP_NAME_END);

			out.setBitmapName(value);
		}
		else if (currentLine.find(ObjectTags::ENCOMPASSING_RECT_COLLIDER) != std::string::npos)
		{
			value = extractStringBetweenTags(currentLine, ObjectTags::ENCOMPASSING_RECT_COLLIDER, ObjectTags::ENCOMPASSING_RECT_COLLIDER_END);

			out.setEncompassingRectColliderTag(value);
		}
		else if (currentLine.find(ObjectTags::END_OF_OBJECT) != std::string::npos)
		{
			return;
		}
	}
}
