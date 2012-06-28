#ifndef _WIN32

#include <sys/time.h>

#include "common.h"
#include "game.h"

namespace
{
	const int WIDTH = 1024, HEIGHT = 768;
	
	Game *game;
	
	double getTime()
	{
		timeval t;
		gettimeofday(&t, NULL);
		return t.tv_sec + t.tv_usec / 1000000.0;
	}
	
	void reshape(int width, int height)
	{
		game->reshape(width, height);
	}
	
	void display()
	{
		// Calculate the elapsed time since the last frame in seconds
		static double prevTime = getTime();
		double dt = getTime() - prevTime;
		prevTime += dt;
		
		game->update(dt);
		game->render();
		
		glutSwapBuffers();
		glutPostRedisplay();
	}
	
	void keyDown(unsigned char key, int x, int y)
	{
		game->keyDown(key, x, y);
	}
	
	void keyUp(unsigned char key, int x, int y)
	{
		game->keyUp(key, x, y);
	}
}

int main(int argc, char **argv)
{
	// Create the main window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("OpenGL demo");
	
	game = new Game();

	// Initialise and register callbacks
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyDown);
	glutKeyboardUpFunc(keyUp);
	reshape(WIDTH, HEIGHT);
	glutIgnoreKeyRepeat(1);
	
	// Enter main loop
	glutMainLoop();
}

#endif
