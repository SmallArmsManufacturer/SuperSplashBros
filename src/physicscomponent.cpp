#include "physicscomponent.h"

#include "common.h"

namespace
{
	float gravity = 9.81f;
#ifdef __linux__
	b2World world(b2Vec2(0.0f, -gravity), false);
#else
	b2World world(b2Vec2(0.0f, -gravity));
#endif
}

void PhysicsComponent::step(double dt)
{
	world.Step(dt, 8, 3);
}

void PhysicsComponent::initRectangle(float x, float y, float width, float height, bool dynamic, bool rotatable)
{
	circle = false;
	this->width = width;
	this->height = height;
	
	b2BodyDef bodyDef;
	bodyDef.type = dynamic ? b2_dynamicBody : b2_staticBody;
	bodyDef.fixedRotation = !rotatable;
	bodyDef.position.Set(x, y);

	body = world.CreateBody(&bodyDef);

	b2PolygonShape poly;
	poly.SetAsBox(width / 2, height / 2);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &poly;
	fixtureDef.density = 0.2;
	fixtureDef.friction = 0.3f;
	fixtureDef.restitution = 0.3f;

	body->CreateFixture(&fixtureDef);
}

void PhysicsComponent::initCircle(float x, float y, float radius, bool dynamic, bool rotatable)
{
	circle = true;
	this->width = radius;
	this->height = radius;
	
	b2BodyDef bodyDef;
	bodyDef.type = dynamic ? b2_dynamicBody : b2_staticBody;
	bodyDef.fixedRotation = !rotatable;
	bodyDef.position.Set(x, y);
	
	body = world.CreateBody(&bodyDef);
	
	b2CircleShape circle;
	circle.m_radius = radius;
	
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &circle;
	fixtureDef.density = 0.2;
	fixtureDef.friction = 0.05f;
	fixtureDef.restitution = 0.1f;
	
	body->CreateFixture(&fixtureDef);
}

float PhysicsComponent::getX()
{
	return body->GetPosition().x;
}

float PhysicsComponent::getY()
{
	return body->GetPosition().y;
}

float PhysicsComponent::getWidth()
{
	return width;
}

float PhysicsComponent::getHeight()
{
	return height;
}


float PhysicsComponent::getAngle()
{
	return body->GetAngle() * 180.0f / M_PI;
}

b2Body* PhysicsComponent::getBody(){
	return body;
}

bool PhysicsComponent::isCircle()
{
	return circle;
}

void PhysicsComponent::applyForce(float x, float y)
{
	getBody()->ApplyLinearImpulse(b2Vec2(x, y), getBody()->GetWorldCenter());
}
