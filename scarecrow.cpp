#include "scarecrow.h"

#include <OpenGL/gl.h>
#include <GLUT/glut.h>

#include "batman.h"
#include "entity.h"

void Scarecrow::render()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	{
		Batman *batman = entity->getComponent<Batman>();
		glRotatef(batman->getAngle(), 0.0f, 0.0f, 1.0f);
		glTranslatef(batman->getX(), batman->getY(), 0.0f);
		glColor3d(1.0, 1.0, 1.0);
		glutSolidCube(1.0);
	}
	glPopMatrix();
}
