#include "StringMap.h"

StringMap::StringMap(unsigned int blocksX, unsigned int blocksY)
{
	this->blocksX = blocksX;
	this->blocksY = blocksY;

	int numberofFields = blocksX * blocksY;

	//set all fields to grass
	for (int i = 0; i < numberofFields; i++) {
		mapString.push_back(FieldType::grassField);
	}
}

StringMap::StringMap(unsigned int blocksX, unsigned int blocksY, vector<int> mapString)
{
	this->blocksX = blocksX;
	this->blocksY = blocksY;

	//wenn mapgroesse nicht mit angegebnen feldern uebereinstimmt wird fehler geworfen
	if (blocksX * blocksY != mapString.size()) {
		throw "check Parameter of MapString!!";
	}

	for (int i = 0; i < mapString.size(); i++) {
		this->mapString.push_back(static_cast<FieldType>(mapString.at(i)));
	}
}

void StringMap::printMapToConsole()
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

FieldType StringMap::getFieldType(unsigned posX, unsigned posY) {
	

	return mapString.at(coordToLine(posX, posY));
	
}

FieldType StringMap::getFieldType(unsigned posLinear) {
	return mapString.at(posLinear);
}

vector<unsigned int> StringMap::lineToCoord(unsigned linePos) {

	vector<unsigned> coord;
	
	int xCoord = linePos % blocksX;
	int yCoord = static_cast<int>(linePos / blocksX);

	coord.push_back(xCoord);
	coord.push_back(yCoord);

	return coord;
}

unsigned StringMap::coordToLine(unsigned posX, unsigned posY) {

	unsigned lineCoord = posY * blocksX + posX;

	return lineCoord;
}

void StringMap::setFieldType(FieldType type, unsigned posX, unsigned posY) {

	mapString.at(coordToLine(posX, posY)) = type;
}

void StringMap::setMapString(vector<FieldType>& mapString){
	this->mapString = mapString;
	cout << &this->mapString << "     " << &mapString;

}

vector<FieldType> StringMap::getMapString()
{
	return this->mapString;
}

unsigned StringMap::getMapSize() {
	return this->mapString.size();
}


StringMap::~StringMap()
{
}
