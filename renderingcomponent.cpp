#include "renderingcomponent.h"

#include "common.h"
#include "physicscomponent.h"
#include "entity.h"

void RenderingComponent::render()
{

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	{
		PhysicsComponent *physicsComponent = entity->getComponent<PhysicsComponent>();
		glTranslatef(physicsComponent->getX(), physicsComponent->getY(), 0.0f);
		glRotatef(physicsComponent->getAngle(), 0.0f, 0.0f, 1.0f);
		glColor3d(1.0, 1.0, 1.0);
		glScalef(physicsComponent->getWidth(), physicsComponent->getHeight(), 1);
		glutSolidCube(1.0);
	}
	glPopMatrix();
}
