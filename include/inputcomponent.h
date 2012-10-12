#pragma once

#include "component.h"

class InputComponent : public Component
{
	public:
		InputComponent();
		void keyDown(unsigned char key, int x, int y);
		void keyUp(unsigned char key, int x, int y);
		void mouseClick(int button, int state);
		void mouseMove(double x, double y, double playerX, double playerY);
		void update(double dt);
	
	private:
		int direction;
};
