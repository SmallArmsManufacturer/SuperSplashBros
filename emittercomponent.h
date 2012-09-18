#pragma once

#include "component.h"


class EmitterComponent : public Component
{
	
	public:
		void init();
		void turnOn();
		void turnOff();
		void update(double dt);
		void setEmissionVector(double x, double y);
	
	private:
		bool on;
		double rate;
		double count;
		double x, y; 
};
