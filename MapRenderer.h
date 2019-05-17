#ifndef MAPRENDERER_H
#define MAPRENDERER_H

#include "GameMap.h"
#include "GameObject.h"

class MapRenderer : public GameObject
{
private:
	GameMap* map;

	float scrollSpeed = 0.5;
	
	bool movingLeft = false;
	bool movingRight = false;
	bool movingUp = false;
	bool movingDown = false;



public:
	MapRenderer(GameMap &map);

	void update(long dT);
	void render(sf::RenderWindow &window);

	void moveLeft(bool movingLeft);
	void moveRight(bool movingRight);
	void moveUp(bool movingUp);
	void moveDown(bool movingDown);




	~MapRenderer();
};


#endif // !MAPRENDERER_H


