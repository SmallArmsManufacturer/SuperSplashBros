#include "entity.h"


class Player : public Entity
{

	public:
		
		void init(float x, float y);
		void processSpecialKeys(int key, int x, int y);
	
};