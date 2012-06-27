#include "tile.h"

#include "physicscomponent.h"
#include "renderingcomponent.h"


void Tile::init(float x, float y)
{
	PhysicsComponent *physicsComponent = Entity::addComponent<PhysicsComponent>();
	physicsComponent->init(x, y, 5.0f, 1.0f, false, false);
	Entity::addComponent<RenderingComponent>();
}