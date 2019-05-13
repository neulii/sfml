#include "GameMap.h"


GameMap::GameMap(StringMap& stringMap, FieldTextureMap& textureMap)
{
	this->stringMap = &stringMap;

	for (int i = 0; i < this->stringMap->getMapSize(); i++) {
		
		unsigned posX = 10;
		unsigned posY = 20;
		
		gameMap.push_back(new ProductionTile(this->stringMap->getFieldType(i), posX, posY, textureMap.at(this->stringMap->getFieldType(i))));


	}
}


GameMap::~GameMap()
{
}
