#include "emittercomponent.h"

#include "common.h"
#include "entity.h"
#include "renderingcomponent.h"
#include "physicscomponent.h"
#include "level.h"

#include <iostream>

void EmitterComponent::init()
{
	on = false;
	rate = 0.02;
	count = 0;
}



void EmitterComponent::turnOn()
{
	on = true;
}

void EmitterComponent::turnOff()
{
	on = false;
}

void EmitterComponent::setEmissionVector(double x, double y)
{
	this->x = x;
	this->y = y;
}


void EmitterComponent::update(double dt)
{	

	if (count > rate)
	{
		count = 0;
		if (on)
		{
			Entity *water = new Entity(); 
			PhysicsComponent *physicsComponent = water->addComponent<PhysicsComponent>();
			physicsComponent->initCircle(entity->getComponent<PhysicsComponent>()->getX() + x, entity->getComponent<PhysicsComponent>()->getY() + y, 0.1f, true, true);
			physicsComponent->applyForce(x, y);
			RenderingComponent *renderingComponent = water->addComponent<RenderingComponent>();
			renderingComponent->init(0.0, 0.5, 1.0, 0.5);
			entity->getLevel()->addEntity(water);
		}
	}
	
	count += dt;
}
