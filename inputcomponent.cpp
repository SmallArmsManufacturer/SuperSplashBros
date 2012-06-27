#include "inputcomponent.h"

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
#include "physicscomponent.h"
#include "entity.h"

void InputComponent::processSpecialKeys(int key, int x, int y) {
	PhysicsComponent *physicsComponent = entity->getComponent<PhysicsComponent>();
	if(key == GLUT_KEY_LEFT){
		physicsComponent->getBody()->ApplyLinearImpulse(b2Vec2(-0.5, 0),physicsComponent->getBody()->GetWorldCenter());
	}else{
		if(key == GLUT_KEY_RIGHT){
			physicsComponent->getBody()->ApplyLinearImpulse(b2Vec2(0.5, 0),physicsComponent->getBody()->GetWorldCenter());
		}
	}
}
