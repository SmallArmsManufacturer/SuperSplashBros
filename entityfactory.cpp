#include "entityfactory.h"

#include "renderingcomponent.h"
#include "physicscomponent.h"
#include "inputcomponent.h"

Entity *EntityFactory::createBox(float x, float y)
{
	Entity *box = new Entity(); 
	PhysicsComponent *physicsComponent = box->addComponent<PhysicsComponent>();
	physicsComponent->init(x, y, 1.0f, 1.0f, true, true);
	box->addComponent<RenderingComponent>();
	return box;
}

Entity *EntityFactory::createTile(float x, float y)
{
	Entity *tile = new Entity();
	PhysicsComponent *physicsComponent = tile->addComponent<PhysicsComponent>();
	physicsComponent->init(x, y, 5.0f, 1.0f, false, false);
	tile->addComponent<RenderingComponent>();
	return tile;
}

Entity *EntityFactory::createPlayer(float x, float y)
{
	Entity *player = new Entity();
	PhysicsComponent *physicsComponent = player->addComponent<PhysicsComponent>();
	physicsComponent->init(x, y, 0.8f, 2.0f, true, false);
	player->addComponent<RenderingComponent>();	
	player->addComponent<InputComponent>();
	return player;
}