#pragma once
#include <vector>
#include <string>
class GameObjectBlueprint
{
private:
	std::string m_Name = "";
	std::vector<std::string> m_ComponentList;
	std::string m_BitmapName = "";
	float m_Width  = 0;
	float m_Height = 0;
	float m_LocationX = 0;
	float m_LocationY = 0;
	float m_Speed = 0;
	bool  m_EncompassingRectCollider = false;
	std::string m_EncompassingRectColliderTag = "";

public:
	float getWidth();
	void setWidth(float width);

	float getHeight();
	void setHeight(float height);

	float getLocationX();
	void setLocationX(float locationX);

	float getLocationY();
	void setLocationY(float locationY);

	void setName(std::string name);
	std::string getName();

	std::vector<std::string>& getComponentList();
	void addToComponentList(std::string component);

	std::string getBitmapName();
	void setBitmapName(std::string toName);

	std::string getEncompassingRectColliderTag();
	bool getEncompassingRectCollider();
	void setEncompassingRectColliderTag(std::string toTag);
};

