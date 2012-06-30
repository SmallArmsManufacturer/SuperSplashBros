#include "emittercomponent.h"

#include "common.h"
#include "entity.h"
#include "renderingcomponent.h"

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
		entity->getComponent<RenderingComponent>()->init(1.0, 0, 1.0, 1.0);
	}
	else
		entity->getComponent<RenderingComponent>()->init(0, 1, 1.0, 1.0);

}
