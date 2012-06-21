#pragma once

class Entity;

class Component
{
	friend class Entity;
	
	public:
		virtual ~Component();
		
	protected:
		Entity *entity;
};
