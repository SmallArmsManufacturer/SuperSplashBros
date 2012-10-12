#include "level.h"

#include "entity.h"
#include "renderingcomponent.h"
#include "inputcomponent.h"
#include "emittercomponent.h"

#include <iostream>

void Level::addEntity(Entity *entity)
{
	newEntities.push_back(entity);
	entity->level = this;
}

void Level::update(double dt)
{
	for(vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
	{
		if ((*it)->getComponent<InputComponent>() != NULL)
			(*it)->getComponent<InputComponent>()->update(dt);
		if ((*it)->getComponent<EmitterComponent>() != NULL)
			(*it)->getComponent<EmitterComponent>()->update(dt);
	}
	
	entities.insert( entities.end(), newEntities.begin(), newEntities.end() );
	newEntities.clear();
}


void Level::render()
{
	for(vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
	{
		if ((*it)->getComponent<RenderingComponent>() != NULL)
			(*it)->getComponent<RenderingComponent>()->render();
	}
}


