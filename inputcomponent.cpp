#include "inputcomponent.h"

#include "common.h"
#include "physicscomponent.h"
#include "renderingcomponent.h"
#include "emittercomponent.h"
#include "entity.h"

#include <math.h>
#include <iostream>
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
	if (key == 'a' || key == 'A')
		direction--;
	else if (key == 'd' || key == 'D')
		direction++;
}

void InputComponent::keyUp(unsigned char key, int x, int y)
{
	if (key == 'a' || key == 'A')
		direction++;
	else if (key == 'd' || key == 'D')
		direction--;
}

void InputComponent::mouseClick(int button, int state)
{	
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
			entity->getComponent<EmitterComponent>()->turnOn();
		else
			entity->getComponent<EmitterComponent>()->turnOff();
	}
}

void InputComponent::mouseMove(double x, double y, double playerX, double playerY)
{
	double tempX = x - playerX;
	double tempY = -(y - playerY);
	
	double cake = sqrt(tempX * tempX + tempY * tempY) * 40.0;
	tempX /= cake;
	tempY /= cake;
	entity->getComponent<EmitterComponent>()->setEmissionVector(tempX, tempY);

}

void InputComponent::update(double dt)
{
	PhysicsComponent *physicsComponent = entity->getComponent<PhysicsComponent>();
	physicsComponent->applyForce(direction * dt * ACCELERATION, 0);
}
