#include "Tile.h"
#include <iostream>

//Tile::Tile(FieldType fieldType, int x, int y, sf::Texture texture) {
Tile::Tile(int x, int y, sf::Texture &texture) {

	tileCounter++;
	//std::cout << tileCounter << std::endl;

	this->x = x;
	this->y = y;
	this->texture = &texture;
	//this->fieldType = fieldType;
	this->width = texture.getSize().x;
	this->height = texture.getSize().y;

	rect.setSize(sf::Vector2f(width, height));

	rect.setPosition(x, y);

	tileSprite.setTexture(*this->texture);
	tileSprite.setPosition(x, y);
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
	tileCounter--;
	//std::cout << tileCounter << std::endl;
}