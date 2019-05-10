#include "Map.h"

Map::Map(unsigned int blocksX, unsigned int blocksY)
{
	this->blocksX = blocksX;
	this->blocksY = blocksY;

	int numberofFields = blocksX * blocksY;

	//set all fields to grass
	for (int i = 0; i < numberofFields; i++) {
		mapString.push_back(FieldType::grassField);
	}
}

void Map::printMapToConsole()
{
	cout << "============   MapString  ============"<< endl;
	
	for (unsigned i = 0; i < mapString.size(); i++) {
		if (i % blocksX == 0) {
			cout << endl;
		}
		cout << mapString.at(i) << "  ";
	}

	cout << endl << endl <<  "========  end of MapString    ========" << endl << endl;
}

FieldType Map::getFieldType(unsigned posX, unsigned posY) {
	

	return mapString.at(coordToLine(posX, posY));
	
}

vector<unsigned int> Map::lineToCoord(unsigned linePos) {

	vector<unsigned> coord;
	
	int xCoord = linePos % blocksX;
	int yCoord = static_cast<int>(linePos / blocksX);

	coord.push_back(xCoord);
	coord.push_back(yCoord);

	return coord;
}

unsigned Map::coordToLine(unsigned posX, unsigned posY) {

	unsigned lineCoord = posY * blocksX + posX;

	return lineCoord;
}

void Map::setFieldType(FieldType type, unsigned posX, unsigned posY) {

	mapString.at(coordToLine(posX, posY)) = type;
}

void Map::setMapString(vector<FieldType>& mapString){
	this->mapString = mapString;
	cout << &this->mapString << "     " << &mapString;

}

vector<FieldType> Map::getMapString()
{
	return this->mapString;
}


Map::~Map()
{
}
