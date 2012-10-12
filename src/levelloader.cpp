#include "levelloader.h"
#include "entityfactory.h"
/*
Red is a tile
Black is player1
Yellow will be player2
Blue will be areas of water
Green is a crate
White is nothing/empty space
*/
 
LevelLoader::LevelLoader(){
	red = new RGBApixel;
	red->Alpha=0;
	red->Blue=0;
	red->Green=0;
	red->Red=255;

	blue = new RGBApixel;
	blue->Alpha=0;
	blue->Blue=255;
	blue->Green=0;
	blue->Red=0;

	green = new RGBApixel;
	green->Alpha=0;
	green->Blue=0;
	green->Green=255;
	green->Red=0;

	black = new RGBApixel;
	black->Alpha=0;
	black->Blue=0;
	black->Green=0;
	black->Red=0;

	yellow = new RGBApixel;
	yellow->Alpha=0;
	yellow->Blue=0;
	yellow->Green=255;
	yellow->Red=255;
};

void LevelLoader::readLevel(Level *level){
	BMP levelImage;
	levelImage.ReadFromFile("level.bmp");
	int offsetX = (levelImage.TellWidth()/2)+1;
	int offsetY = (levelImage.TellHeight()/2)+1;

	//stops more than one player being created
	bool player1Load = false;

	for(int i = 0; i < levelImage.TellWidth(); i++){
		for(int j = 0; j < levelImage.TellHeight(); j++){
			RGBApixel temp = levelImage.GetPixel(i,j);
			if(compare(red, &temp)){
				level->addEntity(EntityFactory::createTile(i-offsetX,levelImage.TellHeight()-j-offsetY));
			}else if(compare(black, &temp) && !player1Load){
				player = EntityFactory::createPlayer(i-offsetX,levelImage.TellHeight()-j-offsetY, 0, 0, 0);
				level->addEntity(player);
				player1Load = true;
			}else if(compare(green, &temp)){
				level->addEntity(EntityFactory::createBox(i-offsetX,levelImage.TellHeight()-j-offsetY));
			}
			
		}
	}
	
};

bool LevelLoader::compare(RGBApixel *first, RGBApixel *second){
	return(first->Alpha == second->Alpha && first->Blue == second->Blue && first->Green == second->Green && first->Red == second->Red);
};

Entity* LevelLoader::getPlayer1(){
	return player;
};



