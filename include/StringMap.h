#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>

#include "FieldType.h"

using namespace std;

class StringMap
{
private:
	vector <FieldType> mapString;

	unsigned int blocksX = 0;
	unsigned int blocksY = 0;

public:
	
	StringMap(unsigned int blocksX, unsigned int blocksY);
	StringMap(unsigned int blocksX, unsigned int blocksY, vector<int> mapString);

	void					printMapToConsole();
	FieldType				getFieldType(unsigned posX, unsigned posY);
	FieldType				getFieldType(unsigned posLinear);
	void					setFieldType(FieldType type, unsigned posX, unsigned posY);
	vector<unsigned int>	lineToCoord(unsigned linePos);
	unsigned				coordToLine(unsigned posX, unsigned posY);
	void					setMapString(vector<FieldType> &mapString);
	vector<FieldType>		getMapString();
	unsigned				getMapSize();

	~StringMap();
};

#endif // !MAP_H