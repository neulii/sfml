#include "GameMap.h"

GameMap::GameMap(StringMap& stringMap, FieldTextureMap& textureMap)
{
	this->stringMap = &stringMap;

	//create tiles for gamemap

	for (unsigned i = 0; i < this->stringMap->getMapSize(); i++) {

		//position der bloecke ermitteln
		unsigned xPosBlocks = stringMap.lineToCoord(i).at(0);	//erster wert ist x-pos
		unsigned yPosBlocks = stringMap.lineToCoord(i).at(1);	//zweiter wert ist y-pos

		//position ausrechnen mit groesse der blocke aus der texture map
		unsigned posX = xPosBlocks * textureMap.at(this->stringMap->getFieldType(i)).getSize().x;
		unsigned posY = yPosBlocks * textureMap.at(this->stringMap->getFieldType(i)).getSize().y;

		//tile erstellen
		gameMap.push_back(new ProductionTile(this->stringMap->getFieldType(i), posX, posY, textureMap.at(this->stringMap->getFieldType(i))));
		//cout << "fieldType: " << this->stringMap->getFieldType(i) << endl;

	}
}

//getTile in blocks
ProductionTile* GameMap::getTileAt(unsigned pos) {
	return gameMap.at(pos);
}

//getTile from pixels
ProductionTile* GameMap::getTileAt(sf::Vector2f pos) {
	ProductionTile *temp = nullptr;

	int tileWidth = gameMap.at(0)->getRect()->getSize().x;
	int tileHeight = gameMap.at(0)->getRect()->getSize().y;

	int posTilesX = pos.x / tileWidth; 
	int posTilesY = pos.y / tileHeight;

	int lineCoord = stringMap->coordToLine(posTilesX, posTilesY);
	temp = gameMap.at(lineCoord);
	//cout << temp->getFieldType() << endl;
	
	return temp;
}

unsigned GameMap::getSize() {
	return gameMap.size();
}

GameMap::~GameMap()
{
}