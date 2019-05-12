#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <vector>
#include "ProductionTile.h"


class GameMap
{
private:
	std::vector<ProductionTile> productionTiles;


public:
	GameMap();

	~GameMap();
};

#endif // !GAMEMAP_H


