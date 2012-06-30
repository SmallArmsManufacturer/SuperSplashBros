#include "inputcomponent.h"

#include "common.h"
#include "physicscomponent.h"
#include "renderingcomponent.h"
#include "emittercomponent.h"
#include "entity.h"

#include <math.h>


namespace
{
	// The impulse applied to players when they move
	const float ACCELERATION = 5.0f;
	
	// The implulse applied to players when they jump
	const float JUMP = 5.0f;
}

InputComponent::InputComponent() : direction(0)
{
}

void InputComponent::keyDown(unsigned char key, int x, int y)
{
	if (key == 'a')
		direction--;
	else if (key == 'd')
		direction++;
	else if (key == ' ')
		entity->getComponent<PhysicsComponent>()->applyForce(0, -JUMP);
}

void InputComponent::keyUp(unsigned char key, int x, int y)
{
	if (key == 'a')
		direction++;
	else if (key == 'd')
		direction--;
}

void InputComponent::mouseClick(int button, int state, int x, int y)
{
	double tempX = x - entity->getComponent<PhysicsComponent>()->getX();
	double tempY = y - entity->getComponent<PhysicsComponent>()->getY();

	//TODO:work out angle
	
	//entity->getComponent<EmitterComponent>()->setAngle(angle);

	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
			entity->getComponent<EmitterComponent>()->turnOn();
		else
			entity->getComponent<EmitterComponent>()->turnOff();
	}
}

void InputComponent::update(double dt)
{
	PhysicsComponent *physicsComponent = entity->getComponent<PhysicsComponent>();
	physicsComponent->applyForce(direction * dt * ACCELERATION, 0);
}
