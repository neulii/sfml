#include "Tile.h"
#include <iostream>

//Tile::Tile(FieldType fieldType, int x, int y, sf::Texture texture) {
Tile::Tile(double x, double y, sf::Texture &texture) {

	tileCounter++;
	//std::cout << tileCounter << std::endl;

	this->x = x;
	this->y = y;
	this->texture = &texture;
	//this->fieldType = fieldType;
	this->width = texture.getSize().x;
	this->height = texture.getSize().y;

	rect.setFillColor(sf::Color::Transparent);
	rect.setSize(sf::Vector2f(static_cast<float>(width), static_cast<float>(height)));
	rect.setPosition(static_cast<float>(x), static_cast<float>(y));

	tileSprite.setTexture(*this->texture);
	tileSprite.setPosition(static_cast<float>(x), static_cast<float>(y));
}

//render the tile
void Tile::render(sf::RenderWindow &window) {
	
	window.draw(tileSprite);
}

//update logic
void Tile::update(long dT) {

}

void Tile::tileToConsole() {
	std::cout << "Pos: " << x << " / " << y <<std::endl;

}

sf::Sprite* Tile::getSprite()
{
	return &tileSprite;
}

sf::RectangleShape* Tile::getRect()
{
	return &rect;
}

bool Tile::contains(sf::Vector2f pos) {
	bool isIn = false;
	
	if (rect.getLocalBounds().contains(pos)) {
		isIn = true;
	}
	
	return isIn;
}


Tile::~Tile()
{
	tileCounter--;
	//std::cout << tileCounter << std::endl;
}