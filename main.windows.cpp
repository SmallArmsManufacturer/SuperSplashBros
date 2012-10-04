#ifdef _WIN32
#include <Windows.h>
#include "common.h"
#include "game.h"
#include <iostream>

namespace
{
	const int WIDTH = 1024, HEIGHT = 768;
	
	Game *game;

	double currentTime = 0;
	double previousTime = 0;

	void reshape(int width, int height)
	{
		game->reshape(width, height);
	}
	
	void display()
	{
		currentTime = glutGet(GLUT_ELAPSED_TIME);
		double timeInterval = currentTime - previousTime;
		previousTime = currentTime;
		
		game->update(timeInterval/1000.0f);
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
	
	void mouseClick(int button, int state, int x, int y)
	{
		game->mouseClick(button, state, x, y);
	}
	
	void mouseMove(int x, int y)
	{
		game->mouseMove(x, y);
	}
	
}

int main(int argc, char **argv){
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
	glutMouseFunc(mouseClick);
	glutMotionFunc(mouseMove);
	reshape(WIDTH, HEIGHT);
	glutIgnoreKeyRepeat(1);
	
	// Enter main loop
	glutMainLoop();
}


#endif
