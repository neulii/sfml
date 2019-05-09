#ifndef MAP_H
#define MAP_H

#include "GameObject.h"
#include "FieldType.h"

using namespace std;

class Map :public GameObject
{
private:
	vector <FieldType> mapString;

	unsigned int blocksX = 0;
	unsigned int blocksY = 0;


public:
	Map(unsigned int blocksX, unsigned int blocksY);

	void update(long dT);
	void render(sf::RenderWindow& window);


	~Map();
};

#endif // !MAP_H