#ifndef PRODUCTIONTILE_H
#define PRODUCTIONTILE_H

#include "Tile.h"
#include <iostream>
class ProductionTile : public Tile
{
private:
	FieldType fieldType;


public:
	//ProductionTile(FieldType fieldType, int x, int y, sf::Texture texture);


	ProductionTile(FieldType fieldType, double x, double y,sf::Texture &texture);
	
	FieldType getFieldType();
	void tileToConsole();
	~ProductionTile();
};


#endif // !PRODUCTIONTILE_H


