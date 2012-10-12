class Entity;
class Level;

namespace EntityFactory
{
	Entity *createBox(float x, float y);
	
	Entity *createTile(float x, float y);
	
	Entity *createPlayer(float x, float y, float r, float g, float b);
		
}
