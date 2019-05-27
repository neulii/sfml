#ifndef MAPRENDERER_H
#define MAPRENDERER_H

#include "GameMap.h"
#include "GameObject.h"

class MapRenderer : public GameObject
{
private:
	GameMap* map;
	sf::RenderWindow* window;

	float scrollSpeed = 0.4;
	
	bool movingLeft = false;
	bool movingRight = false;
	bool movingUp = false;
	bool movingDown = false;

	bool mapIsOnLeftBorder = false;
	bool mapIsOnRightBorder = false;
	bool mapIsOnTopBorder = false;
	bool mapIsOnBottomBorder = false;

public:
	MapRenderer(GameMap &map, sf::RenderWindow &window);

	void update(long dT);
	void render(sf::RenderWindow &window);

	void moveLeft(bool movingLeft);
	void moveRight(bool movingRight);
	void moveUp(bool movingUp);
	void moveDown(bool movingDown);




	~MapRenderer();
};


#endif // !MAPRENDERER_H

