#pragma once

#include "component.h"


class EmitterComponent : public Component
{
	
	public:
		void init();
		void setAngle(float angle);
		void turnOn();
		void turnOff();
		void update(double dt);

	private:
		double angle;
		bool on;
};
