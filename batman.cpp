#include "batman.h"

#include <Box2D/Box2D.h>

namespace
{
	float gravity = 9.81f;
	b2World world(b2Vec2(0.0f, -gravity));
}

void Batman::step(double dt)
{
	world.Step(dt, 8, 3);
}

void Batman::init(float x, float y, float width, float height, bool dynamic, bool rotatable)
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

float Batman::getX()
{
	return body->GetPosition().x;
}

float Batman::getY()
{
	return body->GetPosition().y;
}

float Batman::getAngle()
{
	return body->GetAngle() * 180.0f / M_PI;
}
