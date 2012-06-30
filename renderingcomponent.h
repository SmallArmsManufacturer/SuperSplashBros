#pragma once

#include "component.h"

class RenderingComponent : public Component
{
	public:
		void init(double r, double g, double b, double a);
		void render();
	
	private:
		double r, g, b, a;
};
