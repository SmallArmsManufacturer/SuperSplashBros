#include "box.h"

#include "physicscomponent.h"
#include "renderingcomponent.h"


void Box::init()
{
	Entity();
	PhysicsComponent *physicsComponent = Entity::addComponent<PhysicsComponent>();
	physicsComponent->init(0.0f, 0.0f, 1.0f, 1.0f, true, true);
	Entity::addComponent<RenderingComponent>();
}