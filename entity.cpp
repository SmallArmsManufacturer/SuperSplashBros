#include "entity.h"

#include "component.h"

Entity::~Entity()
{
	for (std::map<const std::type_info *, Component *>::iterator it = components.begin(); it != components.end(); it++)
		delete (*it).second;
}
