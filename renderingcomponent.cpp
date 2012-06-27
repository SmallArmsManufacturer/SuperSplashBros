#include "renderingcomponent.h"

#include <OpenGL/gl.h>
#include <GLUT/glut.h>

#include "physicscomponent.h"
#include "entity.h"

void RenderingComponent::render()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	{
		PhysicsComponent *physicsComponent = entity->getComponent<PhysicsComponent>();
		glRotatef(physicsComponent->getAngle(), 0.0f, 0.0f, 1.0f);
		glTranslatef(physicsComponent->getX(), physicsComponent->getY(), 0.0f);
		glColor3d(1.0, 1.0, 1.0);
		glutSolidCube(1.0);
	}
	glPopMatrix();
}
