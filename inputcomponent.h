#pragma once

#include "component.h"

class InputComponent : public Component
{
	public:
		void processSpecialKeys(int key, int x, int y);
};
