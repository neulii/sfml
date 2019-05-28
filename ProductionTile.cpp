#include "ProductionTile.h"



ProductionTile::ProductionTile(FieldType fieldType, double x, double y, sf::Texture &texture): 
	Tile(x,y,texture){
	
	this->fieldType = fieldType;

}

ProductionTile::~ProductionTile()
{
}
