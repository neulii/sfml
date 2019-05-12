#include "ProductionTile.h"



ProductionTile::ProductionTile(FieldType fieldType, int x, int y, sf::Texture &texture): 
	Tile(x,y,texture){
	
	this->fieldType = fieldType;

}

ProductionTile::~ProductionTile()
{
}
