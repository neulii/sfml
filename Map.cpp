#include "Map.h"



Map::Map(unsigned int blocksX, unsigned int blocksY)
{
	this->blocksX = blocksX;
	this->blocksY = blocksY;

	int numberofFields = blocksX * blocksY;

	for (int i = 0; i < numberofFields; i++) {
		mapString.push_back(FieldType::grassField);
	}

}

void Map::update(long dT) {

}
void Map::render(sf::RenderWindow& window) {

}


Map::~Map()
{
}
