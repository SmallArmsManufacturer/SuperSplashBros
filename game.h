#pragma once

#include <string>

class Entity;

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
	
	private:
		Entity *box, *tile, *player;
};
