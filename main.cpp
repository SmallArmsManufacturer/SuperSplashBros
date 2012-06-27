#ifdef __APPLE__
	#include <GLUT/glut.h>
	#include <OpenGL/gl.h>
	#include <sys/time.h>
#else
	#ifdef _WIN32
		#include <Windows.h>
	#else
		#include <sys/time.h>
	#endif
	#include <GL/glut.h>
	#include <GL/GL.h>
#endif
#include <iostream>

#include "entity.h"
#include "physicscomponent.h"
#include "renderingcomponent.h"

#ifdef _WIN32
	//  The number of frames
	int frameCount = 0;

	//  Number of frames per second
	float fps = 60;
	int currentTime = 0;
	int previousTime = 0;
	typedef BOOL (APIENTRY *PFNWGLSWAPINTERVALFARPROC)( int );
	typedef int (*PFNWGLEXTGETSWAPINTERVALPROC) (void);

	PFNWGLSWAPINTERVALFARPROC wglSwapIntervalEXT = 0;
	PFNWGLEXTGETSWAPINTERVALPROC wglGetSwapIntervalEXT = 0;
	void calculateFPS();
	void setVSync(int interval);
#endif

using namespace std;

namespace
{
	// The default window size
	const int WIDTH = 1024, HEIGHT = 768;
	
	Entity box;
	#ifndef _WIN32
		double getTime()
		{
			timeval t;
			gettimeofday(&t, NULL);
			return t.tv_sec + t.tv_usec / 1000000.0;
		}
	#endif

	void init()
	{
		// Set the background colour to light blue
		glClearColor(0.5f, 0.6f, 1.0f, 1.0f);

		// Set up the modelview matrix (i.e. position the camera 10 metres along the positive Z axis)
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslated(0.0, 0.0, -10.0);
		
		PhysicsComponent *physicsComponent = box.addComponent<PhysicsComponent>();
		physicsComponent->init(0.0f, 0.0f, 1.0f, 1.0f, true, true);
		box.addComponent<RenderingComponent>();
		#ifdef _WIN32
			setVSync(1);
		#endif
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
#ifndef _WIN32
		// Calculate the elapsed time since the last frame in seconds
		static double prevTime = getTime();
		double dt = getTime() - prevTime;
		prevTime += dt;

#else
		calculateFPS();
		double dt = 1/fps;
#endif
		PhysicsComponent::step(dt);
		
		
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT);
		
		// Draw a white, solid, 1x1x1 meter cube at the origin
		box.getComponent<RenderingComponent>()->render();

		// Swap the buffers
		glFlush();
		glutSwapBuffers();

		// Tell GLUT to re-run the display func as soon as possible
		glutPostRedisplay();
	}
}
#ifdef _WIN32
	void calculateFPS()
	{
		//  Increase frame count
		frameCount++;

		//  Get the number of milliseconds since glutInit called 
		currentTime = glutGet(GLUT_ELAPSED_TIME);

		//  Calculate time passed
		int timeInterval = currentTime - previousTime;

		if(timeInterval > 1000)
		{
			//  calculate the number of frames per second
			fps = frameCount / (timeInterval / 1000.0f);
			cout << fps << endl;

			//  Set time
			previousTime = currentTime;
			//  Reset frame count
			frameCount = 0;
		}
	}

	void setVSync(int interval)
	{
		wglSwapIntervalEXT = (PFNWGLSWAPINTERVALFARPROC)wglGetProcAddress("wglSwapIntervalEXT");
		wglGetSwapIntervalEXT = (PFNWGLEXTGETSWAPINTERVALPROC)wglGetProcAddress("wglGetSwapIntervalEXT");

		int a = -1;
		if( wglSwapIntervalEXT ){
			wglSwapIntervalEXT(interval);
			a = wglGetSwapIntervalEXT();
		}
		std::cout << a << std::endl;
	}
#endif

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
