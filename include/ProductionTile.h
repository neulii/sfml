#ifndef PRODUCTIONTILE_H
#define PRODUCTIONTILE_H

#include "Tile.h"
class ProductionTile : public Tile
{
private:
	FieldType fieldType;


public:
	//ProductionTile(FieldType fieldType, int x, int y, sf::Texture texture);


	ProductionTile(FieldType fieldType, int x, int y,sf::Texture &texture);

	
	~ProductionTile();
};


#endif // !PRODUCTIONTILE_H


