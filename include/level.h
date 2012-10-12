#pragma once

#include <vector>

using namespace std;

class Entity;

class Level
{
	public:
		void addEntity(Entity* entity);
		void render();
		void update(double dt);
		
	private:
		vector<Entity *> entities;
		vector<Entity *> newEntities;
};

