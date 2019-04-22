#include "Tile.h"
#include <iostream>

Tile::Tile(FieldType fieldType, int x, int y, sf::Texture texture) {

	this->x = x;
	this->y = y;
	this->texture = texture;
	this->fieldType = fieldType;
	this->width = texture.getSize().x;
	this->height = texture.getSize().y;

	rect.setSize(sf::Vector2f(width, height));

	rect.setPosition(x, y);
	
	tileSprite.setTexture(this->texture);
	tileSprite.setPosition(x, y);

	//sf::Uint8 light = 50; // 255 = initial brightness, 0 = black
	//tileSprite.setColor(sf::Color(light, light, light));

	

}


//render the tile
void Tile::render(sf::RenderWindow &window) {
	
	window.draw(tileSprite);

}

//update logic
void Tile::update(long dT) {

}


Tile::~Tile()
{

}