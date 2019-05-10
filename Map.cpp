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
	//TODO gehört noch ausprogrammiert
	return static_cast<FieldType>(mapString.at(posX));
}

vector<unsigned int> Map::lineToCoord(unsigned linePos) {

	vector<unsigned> coord;
	
	int xCoord = linePos % blocksX;
	int yCoord = static_cast<int>(linePos / blocksX);

	coord.push_back(xCoord);
	coord.push_back(yCoord);

	return coord;
}

unsigned Map::lineToCoord(vector<unsigned> coord) {

}

void Map::setFieldType(FieldType type, unsigned posX, unsigned posY) {

	

}

Map::~Map()
{
}
