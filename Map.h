#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>

#include "FieldType.h"

using namespace std;

class Map
{
private:
	vector <FieldType> mapString;

	unsigned int blocksX = 0;
	unsigned int blocksY = 0;

public:
	Map(unsigned int blocksX, unsigned int blocksY);

	void printMapToConsole();
	FieldType getFieldType(unsigned posX, unsigned posY);
	void setFieldType(FieldType type, unsigned posX, unsigned posY);
	vector<unsigned int>lineToCoord(unsigned linePos);
	unsigned coordToLine(unsigned posX, unsigned posY);
	~Map();
};

#endif // !MAP_H