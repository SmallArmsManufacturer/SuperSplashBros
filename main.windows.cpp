#ifdef _WIN32
#include <Windows.h>
#include "common.h"
#include "game.h"

namespace
{
	const int WIDTH = 1024, HEIGHT = 768;
	
	Game *game;
	//  The number of frames
	int frameCount = 0;

	//  Number of frames per second
	float fps = 60;
	int currentTime = 0;
	int previousTime = 0;

	void calculateFPS(){
		//  Increase frame count
		frameCount++;

		//  Get the number of milliseconds since glutInit called 
		currentTime = glutGet(GLUT_ELAPSED_TIME);

		//  Calculate time passed
		int timeInterval = currentTime - previousTime;

		if(timeInterval > 1000){
			//  calculate the number of frames per second
			fps = frameCount / (timeInterval / 1000.0f);
			//cout << fps << endl;

			//  Set time
			previousTime = currentTime;
			//  Reset frame count
			frameCount = 0;
		}
	}
	void reshape(int width, int height)
	{
		game->reshape(width, height);
	}
	
	void display()
	{
		calculateFPS();
		
		game->update(1/fps);
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
