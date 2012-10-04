#pragma once

#include "level.h"
#include <EasyBMP.h>
#include "entity.h"

class LevelLoader{
	public:
		LevelLoader();
		void readLevel(Level *level);
		bool compare(RGBApixel *first, RGBApixel *second);
		Entity* getPlayer1();

	private:
		RGBApixel *red;
		RGBApixel *blue;
		RGBApixel *green;
		RGBApixel *black;
		RGBApixel *yellow;
		int offsetX;
		int offSetY;
		Entity *player;
};