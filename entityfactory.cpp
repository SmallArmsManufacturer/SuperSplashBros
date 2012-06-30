#include "entityfactory.h"

#include "entity.h"
#include "renderingcomponent.h"
#include "physicscomponent.h"
#include "inputcomponent.h"
#include "emittercomponent.h"

Entity *EntityFactory::createBox(float x, float y)
{
	Entity *box = new Entity(); 
	PhysicsComponent *physicsComponent = box->addComponent<PhysicsComponent>();
	physicsComponent->init(x, y, 1.0f, 1.0f, true, true);
	RenderingComponent *renderingComponent = box->addComponent<RenderingComponent>();
	renderingComponent->init(1.0, 1.0, 1.0, 1.0);
	return box;
}

Entity *EntityFactory::createTile(float x, float y)
{
	Entity *tile = new Entity();
	PhysicsComponent *physicsComponent = tile->addComponent<PhysicsComponent>();
	physicsComponent->init(x, y, 5.0f, 1.0f, false, false);
	RenderingComponent *renderingComponent = tile->addComponent<RenderingComponent>();
	renderingComponent->init(1.0, 1.0, 1.0, 1.0);
	return tile;
}

Entity *EntityFactory::createPlayer(float x, float y, float r, float g, float b)
{
	Entity *player = new Entity();
	PhysicsComponent *physicsComponent = player->addComponent<PhysicsComponent>();
	physicsComponent->init(x, y, 0.8f, 2.0f, true, false);
	RenderingComponent *renderingComponent = player->addComponent<RenderingComponent>();
	renderingComponent->init(r, g, b, 0.5);
	player->addComponent<EmitterComponent>();
	player->addComponent<InputComponent>();
	return player;
}
