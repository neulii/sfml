#include "Tile.h"

Tile::Tile(FieldType fieldType, int x, int y, int width, int height, sf::Texture texture) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->texture = texture;
	this->fieldType = fieldType;
}


Tile::~Tile()
{
}

void Tile::render(sf::RenderWindow &window) {
	



	
}

void Tile::update(long dT) {

}