#include "emittercomponent.h"

#include "common.h"
#include "entity.h"
#include "renderingcomponent.h"
#include "physicscomponent.h"
#include "level.h"

void EmitterComponent::init()
{
	on = false;
}

void EmitterComponent::setAngle(float angle)
{
	this->angle = angle;
}

void EmitterComponent::turnOn()
{
	on = true;
}

void EmitterComponent::turnOff()
{
	on = false;
}

void EmitterComponent::update(double dt)
{
	if (on)
	{
		/*Entity *water = new Entity(); 
		PhysicsComponent *physicsComponent = water->addComponent<PhysicsComponent>();
		physicsComponent->init(1, 0.1, 1.0f, 1.0f, true, true);
		RenderingComponent *renderingComponent = water->addComponent<RenderingComponent>();
		renderingComponent->init(0.0, 0.5, 1.0, 0.5);
		entity->getLevel()->addEntity(water);*/
	}
}
