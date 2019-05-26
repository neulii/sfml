#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <vector>
#include "ProductionTile.h"
#include "StringMap.h"
#include "Types.h"

class GameMap
{
private:
	std::vector<ProductionTile*> gameMap;
	StringMap *stringMap = 0;


public:
	/*GameMap(StringMap &stringMap);*/
	GameMap(StringMap& stringMap,FieldTextureMap &textureMap);

	//getTile in bocks
	ProductionTile* getTileAt(unsigned pos);

	//getTile in xpos/ypos
	ProductionTile* getTileAt(sf::Vector2f pos);

	unsigned getSize();


	~GameMap();
};

#endif // !GAMEMAP_H
