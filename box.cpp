#include "box.h"

#include "physicscomponent.h"
#include "renderingcomponent.h"


void Box::init(float x, float y)
{
	PhysicsComponent *physicsComponent = Entity::addComponent<PhysicsComponent>();
	physicsComponent->init(x, y, 1.0f, 1.0f, true, true);
	Entity::addComponent<RenderingComponent>();
}