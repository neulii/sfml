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
	StringMap *stringMap;


public:
	/*GameMap(StringMap &stringMap);*/
	GameMap(StringMap& stringMap,FieldTextureMap &textureMap);

	~GameMap();
};

#endif // !GAMEMAP_H


