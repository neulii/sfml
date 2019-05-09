#ifndef MAP_H
#define MAP_H

#include "GameObject.h"

using namespace std;

class Map :public GameObject
{
private:
	vector <int> mapString;
	


public:
	Map();

	void update(long dT);
	void render(sf::RenderWindow& window);


	~Map();
};

#endif // !MAP_H