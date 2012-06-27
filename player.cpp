#include "player.h"

#include "physicscomponent.h"
#include "renderingcomponent.h"
#ifdef __APPLE__
	#include <GLUT/glut.h>
	#include <sys/time.h>
#else
	#ifdef _WIN32
		#include <Windows.h>
		#include <GL/glut.h>
	#endif
#endif

#include <Box2D/Box2D.h>
PhysicsComponent *physicsComponent;

void Player::init(float x, float y)
{
	physicsComponent = Entity::addComponent<PhysicsComponent>();
	physicsComponent->init(x, y, 0.8f, 2.0f, true, false);
	Entity::addComponent<RenderingComponent>();
}

void Player::processSpecialKeys(int key, int x, int y) {
	if(key == GLUT_KEY_LEFT){
		physicsComponent->getBody()->ApplyLinearImpulse(b2Vec2(-0.5, 0),physicsComponent->getBody()->GetWorldCenter());
	}else{
		if(key == GLUT_KEY_RIGHT){
			physicsComponent->getBody()->ApplyLinearImpulse(b2Vec2(0.5, 0),physicsComponent->getBody()->GetWorldCenter());
		}
	}
}