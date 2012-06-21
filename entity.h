#pragma once

#include <map>
#include <typeinfo>

class Component;

class Entity
{
	public:
		template <typename T> T *addComponent();
		template <typename T> T *getComponent();
		template <typename T> void removeComponent();
		~Entity();
	
	private:
		std::map<const std::type_info *, Component *> components;
};

template <typename T>
T *Entity::addComponent()
{
	T *result = new T();
	Component *component = dynamic_cast<Component *>(result);
	
	if (component == NULL) {
		delete result;
		result = NULL;
	} else {
		result->entity = this;
		components[&typeid(T)] = component;
	}
	
	return result;
}

template <typename T>
T *Entity::getComponent()
{
	return (T *) components[&typeid(T)];
}

template <typename T>
void Entity::removeComponent()
{
	components.erase(&typeid(T));
}
