#include "renderingcomponent.h"

#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <GLUT/glut.h>
#else
	#ifdef _WIN32
		#include <Windows.h>
	#endif
	#include <GL/GL.h>
	#include <GL/glut.h>
#endif

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
		glScalef(physicsComponent->getWidth(), physicsComponent->getHeight(), 1);
		glutSolidCube(1.0);
	}
	glPopMatrix();
}
