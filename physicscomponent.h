#pragma once

#include "component.h"

class b2Body;

class PhysicsComponent : public Component
{
	public:
		void init(float x, float y, float width, float height, bool dynamic, bool rotatable);
		float getX();
		float getY();
		float getAngle();
		static void step(double dt);
	
	private:
		b2Body *body;
};
