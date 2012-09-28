#include "renderingcomponent.h"

#include "common.h"
#include "physicscomponent.h"
#include "entity.h"

void RenderingComponent::init(double r, double g, double b, double a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}


void RenderingComponent::render()
{

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	{
		PhysicsComponent *physicsComponent = entity->getComponent<PhysicsComponent>();
		glTranslatef(physicsComponent->getX(), physicsComponent->getY(), 0.0f);
		glRotatef(physicsComponent->getAngle(), 0.0f, 0.0f, 1.0f);
		glColor4d(r, g, b, a);
		if (physicsComponent->isCircle())
		{
			glScalef(physicsComponent->getWidth() * 2, physicsComponent->getHeight() * 2, physicsComponent->getHeight() * 2);
			glutSolidSphere(1.0, 10, 10);
		}
		else
		{
			glScalef(physicsComponent->getWidth(), physicsComponent->getHeight(), 1);
			glutSolidCube(1.0);
		}
	}
	glPopMatrix();
}
