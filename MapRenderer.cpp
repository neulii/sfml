#include "MapRenderer.h"

MapRenderer::MapRenderer(GameMap &map)
{
	this->map = &map;

}

void MapRenderer::update(long dT)
{
	for (int i = 0; i < map->getSize(); i++) {

		//map->getTileAt(i)->render(window);
		sf::Sprite* sprite = map->getTileAt(i)->getSprite();

		sprite->move(offSetX, offSetY);

		




		
	}

}




void MapRenderer::render(sf::RenderWindow& window)
{
	for (int i = 0; i < map->getSize(); i++) {

		//map->getTileAt(i)->render(window);
		sf::Sprite* sprite = map->getTileAt(i)->getSprite();
		
		float x = sprite->getPosition().x;
		float y = sprite->getPosition().y;

		


		window.draw(*sprite);
	}

}

void MapRenderer::moveLeft(long dT)
{
	cout << offSetX << endl;
	offSetX = offSetX -  scrollSpeed;

}

void MapRenderer::moveRight(long dT)
{
	cout << offSetX << endl;
	offSetX = offSetX + scrollSpeed;

}


MapRenderer::~MapRenderer()
{
}
