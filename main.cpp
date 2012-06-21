#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <sys/time.h>
#include <iostream>

#include "entity.h"
#include "batman.h"
#include "scarecrow.h"

using namespace std;

namespace
{
	// The default window size
	const int WIDTH = 1024, HEIGHT = 768;
	
	Entity box;
	
	double getTime()
	{
		timeval t;
		gettimeofday(&t, NULL);
		return t.tv_sec + t.tv_usec / 1000000.0;
	}

	void init()
	{
		// Set the background colour to light blue
		glClearColor(0.5f, 0.6f, 1.0f, 1.0f);

		// Set up the modelview matrix (i.e. position the camera 10 metres along the positive Z axis)
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslated(0.0, 0.0, -10.0);
		
		Batman *batman = box.addComponent<Batman>();
		batman->init(0.0f, 0.0f, 1.0f, 1.0f, true, true);
		box.addComponent<Scarecrow>();
	}

	void reshape(int width, int height)
	{
		// Resize the OpenGL viewport
		glViewport(0, 0, width, height);

		// Set up the projection matrix with a vertical FOV of 45 degrees with the near clipping plane 1 metre away and the far one 100 metres away
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0, (double) width / height, 1.0, 100.0);
	}

	void display()
	{
		// Calculate the elapsed time since the last frame in seconds
		static double prevTime = getTime();
		double dt = getTime() - prevTime;
		prevTime += dt;
		Batman::step(dt);
		
		// Calculate the framerate
		static double elapsedTime;
		static int numFrames;
		elapsedTime += dt;
		numFrames++;
		
		// Print the framerate to standard output every second
		if (elapsedTime > 1)
		{
			cout << numFrames << endl;
			elapsedTime--;
			numFrames = 0;
		}
		
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT);
		
		// Draw a white, solid, 1x1x1 meter cube at the origin
		box.getComponent<Scarecrow>()->render();

		// Swap the buffers
		glFlush();
		glutSwapBuffers();

		// Tell GLUT to re-run the display func as soon as possible
		glutPostRedisplay();
	}
}

int main(int argc, char *argv[])
{
	// Create the main window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("OpenGL demo");

	// Initialise and register callbacks
	init();
	reshape(WIDTH, HEIGHT);
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMainLoop();
}
