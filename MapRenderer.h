#ifndef MAPRENDERER_H
#define MAPRENDERER_H

#include "GameMap.h"
#include "GameObject.h"

class MapRenderer : public GameObject
{
private:
	GameMap* map;
	int windowHeight;
	int windowWidth;
	sf::Vector2f mousePos;

	float scrollSpeed = 0.4f;

	bool movingLeft = false;
	bool movingRight = false;
	bool movingUp = false;
	bool movingDown = false;

	bool mapIsOnLeftBorder = false;
	bool mapIsOnRightBorder = false;
	bool mapIsOnTopBorder = false;
	bool mapIsOnBottomBorder = false;

public:
	MapRenderer(GameMap& map, int windowWidth, int windowHeight);

	void update(long dT);
	void render(sf::RenderWindow& window);

	void moveLeft(bool movingLeft);
	void moveRight(bool movingRight);
	void moveUp(bool movingUp);
	void moveDown(bool movingDown);
	void processMoving(long dT);

	void setMousePos(sf::Vector2f mousePos);


	~MapRenderer();
};
#endif // !MAPRENDERER_H


