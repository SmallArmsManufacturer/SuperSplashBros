#include "game.h"

#include "common.h"
#include "entity.h"
#include "entityfactory.h"
#include "renderingcomponent.h"
#include "physicscomponent.h"
#include "inputcomponent.h"
#include "emittercomponent.h"
#include "level.h"

#include <iostream>

Game::Game()
{
	// Set the background colour to light blue
	glClearColor(1.0f, 0.6f, 0.0f, 1.0f);
	
	// Set up the modelview matrix (i.e. position the camera 10 metres along the positive Z axis)
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslated(0.0, 0.0, -10.0);
	
	level = new Level(); 

	
	level->addEntity(EntityFactory::createBox(-1.5, 0));
	level->addEntity(EntityFactory::createTile(0,-2));
	player = EntityFactory::createPlayer(0,0, 0, 0, 0);
	level->addEntity(player);
}

Game::~Game()
{
	//TODO: write a level destructor to delete the entities
	delete level;
	delete player;
}

void Game::reshape(int width, int height)
{
	// Resize the OpenGL viewport
	glViewport(0, 0, width, height);

	// Set up the projection matrix with a vertical FOV of 45 degrees with the near clipping plane 1 metre away and the far one 100 metres away
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double) width / height, 1.0, 20.0);
}

void Game::update(double dt)
{
	PhysicsComponent::step(dt);
	level->update(dt);
}

void Game::render()
{
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT);
	

	level->render();
	
	// Swap the buffers
	glFlush();
}

void Game::keyDown(unsigned char key, int x, int y)
{
	player->getComponent<InputComponent>()->keyDown(key, x, y);
}

void Game::keyUp(unsigned char key, int x, int y)
{
	player->getComponent<InputComponent>()->keyUp(key, x, y);
}

void Game::mouseClick(int button, int state, int x, int y)
{
	mouseMove(x, y);
	player->getComponent<InputComponent>()->mouseClick(button, state);
}

void Game::mouseMove(int x, int y)
{
	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLdouble winX, winY, winZ;
	
	glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
	glGetDoublev( GL_PROJECTION_MATRIX, projection );
	glGetIntegerv( GL_VIEWPORT, viewport );
	
	gluProject(player->getComponent<PhysicsComponent>()->getX(),
			   player->getComponent<PhysicsComponent>()->getY(),
			   0.0,
			   modelview,
			   projection,
			   viewport,
			   &winX,
			   &winY,
			   &winZ);

	
	player->getComponent<InputComponent>()->mouseMove(x, y, winX, winY);
}