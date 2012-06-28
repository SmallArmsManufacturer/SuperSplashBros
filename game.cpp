#include "game.h"

#include "common.h"
#include "entity.h"
#include "entityfactory.h"
#include "renderingcomponent.h"
#include "physicscomponent.h"
#include "inputcomponent.h"

Game::Game()
{
	// Set the background colour to light blue
	glClearColor(0.5f, 0.6f, 1.0f, 1.0f);

	// Set up the modelview matrix (i.e. position the camera 10 metres along the positive Z axis)
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslated(0.0, 0.0, -10.0);
	
	box = EntityFactory::createBox(-1.5, 0);
	tile = EntityFactory::createTile(0,-2);
	player = EntityFactory::createPlayer(0,0);
}

Game::~Game()
{
	delete box;
	delete tile;
	delete player;
}

void Game::reshape(int width, int height)
{
	// Resize the OpenGL viewport
	glViewport(0, 0, width, height);

	// Set up the projection matrix with a vertical FOV of 45 degrees with the near clipping plane 1 metre away and the far one 100 metres away
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double) width / height, 1.0, 100.0);
}

void Game::update(double dt)
{
	PhysicsComponent::step(dt);
	player->getComponent<InputComponent>()->update(dt);
}

void Game::render()
{
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT);

	// Render the entities (TODO: put them in a std::vector maybe?)
	box->getComponent<RenderingComponent>()->render();
	tile->getComponent<RenderingComponent>()->render();
	player->getComponent<RenderingComponent>()->render();
	
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
