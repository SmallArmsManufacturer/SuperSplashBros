#pragma once

#include "component.h"

class b2Body;

class PhysicsComponent : public Component
{
	public:
		void init(float x, float y, float width, float height, bool dynamic, bool rotatable);
		float getX();
		float getY();
		float getWidth();
		float getHeight();
		float getAngle();
		static void step(double dt);
		b2Body* getBody();
	
	private:
		b2Body *body;
		float width;
		float height;
};
