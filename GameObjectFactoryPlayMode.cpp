#include "GameObjectFactoryPlayMode.h"
#include "TransformComponent.h"
#include <vector>
#include "GameObject.h"
#include "GameObjectBlueprint.h"
#include <iostream>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include "PlayerUpdateComponent.h"
#include "InvaderUpdateComponent.h"
#include "BulletUpdateComponent.h"
#include "StandardGraphicsComponent.h"
#include "RectColliderComponent.h"
#include <SFML/Graphics/Rect.hpp>

void GameObjectFactoryPlayMode::buildGameObject(GameObjectBlueprint& gameObjectBlueprint, std::vector<GameObject>& gameObjects)
{
	GameObject gameObject;
	gameObject.setTag(gameObjectBlueprint.getName());

	for (auto& component : gameObjectBlueprint.getComponentList())
	{
		if (component == "Transform")
		{
			sf::FloatRect rect = 
			{
				sf::Vector2f(gameObjectBlueprint.getLocationX(), gameObjectBlueprint.getLocationY()),
				sf::Vector2f(gameObjectBlueprint.getWidth(), gameObjectBlueprint.getHeight())
			};

			gameObject.addComponent(std::make_shared<TransformComponent>(rect));
		}
		else if (component == "Player Update")
		{
			gameObject.addComponent(std::make_shared<PlayerUpdateComponent>());
		}
		else if (component == "Invader Update")
		{
			gameObject.addComponent(std::make_shared<InvaderUpdateComponent>());
		}
		else if (component == "Bullet Update")
		{
			gameObject.addComponent(std::make_shared<BulletUpdateComponent>());
		}
		else if (component == "Standard Graphics")
		{
			std::shared_ptr sgc = std::make_shared<StandardGraphicsComponent>();
			sgc->initializeGraphics(gameObjectBlueprint.getBitmapName(), { gameObjectBlueprint.getWidth(), gameObjectBlueprint.getHeight()});

			gameObject.addComponent(sgc);
		}		
		else if (gameObjectBlueprint.getEncompassingRectCollider())
		{
			std::shared_ptr rrc = std::make_shared<RectColliderComponent>();
			rrc->setColliderRect(
				{
					sf::Vector2f(gameObjectBlueprint.getLocationX(), gameObjectBlueprint.getLocationY()),
					sf::Vector2f(gameObjectBlueprint.getWidth(),	 gameObjectBlueprint.getHeight())
				}
			);

			gameObject.addComponent(rrc);
		}

	}
	gameObjects.push_back(gameObject);
}
