#ifndef MAPRENDERER_H
#define MAPRENDERER_H

#include "GameMap.h"
#include "GameObject.h"

class MapRenderer : public GameObject
{
public:
	MapRenderer(sf::RenderWindow &window, GameMap &map);

	void update(long dT);
	void render(sf::RenderWindow &window);





	~MapRenderer();
};


#endif // !MAPRENDERER_H


