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
	rate = 0.005;
	count = 0;
	x = 0;
	y = 0;
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

	while (count > rate)
	{
		count -= rate;
		if (on)
		{
			double randSize = (double)(rand() % 100) / 2000;
			Entity *water = new Entity(); 
			PhysicsComponent *physicsComponent = water->addComponent<PhysicsComponent>();
			physicsComponent->initCircle(entity->getComponent<PhysicsComponent>()->getX() + x, entity->getComponent<PhysicsComponent>()->getY() + y, 0.03f + randSize, true, true);
			physicsComponent->applyForce(x , y );
			entity->getComponent<PhysicsComponent>()->applyForce(-x / 3, -y / 3);
			RenderingComponent *renderingComponent = water->addComponent<RenderingComponent>();
			renderingComponent->init(0.0, 0.7, 1.0, 1);
			entity->getLevel()->addEntity(water);
		}
	}
	
	count += dt;
}
