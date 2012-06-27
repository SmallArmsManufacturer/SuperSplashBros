#include "physicscomponent.h"

#include <Box2D/Box2D.h>

namespace
{
	float gravity = 9.81f;
	b2World world(b2Vec2(0.0f, -gravity));
}

void PhysicsComponent::step(double dt)
{
	world.Step(dt, 8, 3);
}

void PhysicsComponent::init(float x, float y, float width, float height, bool dynamic, bool rotatable)
{
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
	fixtureDef.restitution = 1.0f;
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

float PhysicsComponent::getAngle()
{
	return body->GetAngle() * 180.0f / M_PI;
}