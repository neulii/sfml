#include "ProductionTile.h"



ProductionTile::ProductionTile(FieldType fieldType, double x, double y, sf::Texture &texture): 
	Tile(x,y,texture){
	
	this->fieldType = fieldType;

}

FieldType ProductionTile::getFieldType() {
	return fieldType;

}

void ProductionTile::tileToConsole()
{
	Tile::tileToConsole();
	std::cout << fieldType << std::endl;
	
}

ProductionTile::~ProductionTile()
{
}
