#include "inputcomponent.h"

#include "common.h"
#include "physicscomponent.h"
#include "renderingcomponent.h"
#include "emittercomponent.h"
#include "entity.h"

#include <math.h>

#define _USE_MATH_DEFINES


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

void InputComponent::mouseClick(int button, int state, double x, double y, double playerX, double playerY)
{
	double tempX = x - playerX;
	double tempY = y - playerY;
	
	double angle = atan (tempY / tempX);

	
	if (tempX < 0 && tempY > 0)
		angle += M_PI;
	else if (tempX < 0 && tempY < 0)
		angle += M_PI;
	else if (tempX > 0 && tempY < 0)
		angle += 2.0 * M_PI;
	
	 entity->getComponent<EmitterComponent>()->setAngle(angle);

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
