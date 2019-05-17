#ifndef MAPRENDERER_H
#define MAPRENDERER_H

#include "GameMap.h"
#include "GameObject.h"

class MapRenderer : public GameObject
{
private:
	GameMap* map;
	int offSetX = 0;
	int offSetY = 0;
	float scrollSpeed = 1;
	



public:
	MapRenderer(GameMap &map);

	void update(long dT);
	void render(sf::RenderWindow &window);

	void moveLeft(long dT);
	void moveRight(long dT);
	void moveUp(long dT);
	void moveDown(long dT);




	~MapRenderer();
};


#endif // !MAPRENDERER_H


