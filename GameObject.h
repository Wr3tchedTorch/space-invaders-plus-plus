#pragma once
#include <vector>
#include <memory>
#include "Component.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <string>
#include "GraphicsComponent.h"
#include "UpdateComponent.h"
#include "TransformComponent.h"

class GameObject
{
private:
	std::vector<std::shared_ptr<Component>> m_Components;
	std::string m_Tag;

	bool m_isActive;

	int m_NumberUpdateComponents = 0;
	bool m_HasUpdateComponent    = false;
	int m_FirstUpdateComponentLocation = -1;

	int m_GraphicsComponentLocation = -1;
	bool m_HasGraphicsComponent = false;

	int m_TransformComponentLocation = -1;
	
	int m_NumberRectColliderComponents = 0;
	int m_FirstRectColliderComponentLocation = -1;
	bool m_HasCollider = false;

public:
	void update(float delta);
	void draw(sf::RenderTarget& target);
	void addComponent(std::shared_ptr<Component> component);

	std::shared_ptr<Component> getComponentByTypeAndSpecificType(std::string type, std::string specificType);

	void start(GameObjectSharer* gameObjectSharer);
	void setActive();
	void setInactive();
	bool getIsActive();

	std::string getTag();
	void setTag(std::string);

	sf::FloatRect& getEncompassingRectCollider();
	bool hasCollider();
	bool hasUpdateComponent();
	std::string getEncompassingRectColliderTag();

	std::shared_ptr<GraphicsComponent>  getGraphicsComponent();
	std::shared_ptr<TransformComponent> getTransformComponent();
	std::shared_ptr<UpdateComponent>	getFirstUpdateComponent();

};

