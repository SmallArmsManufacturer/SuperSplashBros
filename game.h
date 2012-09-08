#pragma once

#include <string>

class Entity;
class Level;

class Game
{
	public:
		Game();
		~Game();
		void reshape(int width, int height);
		void update(double dt);
		void render();
		void keyDown(unsigned char key, int x, int y);
		void keyUp(unsigned char key, int x, int y);
		void mouseClick(int button, int state, int x, int y);
	
	private:
		Level *level;
		Entity *player;
};
