#include "MapRenderer.h"

MapRenderer::MapRenderer(GameMap &map)
{
	this->map = &map;

}

void MapRenderer::update(long dT)
{
	for (int i = 0; i < map->getSize(); i++) {
		
		sf::Sprite* sprite = map->getTileAt(i)->getSprite();

		if (movingLeft) {
			sprite->move(scrollSpeed * dT, 0);
		}

		if (movingRight) {	
				sprite->move(-scrollSpeed * dT, 0);
		}

		if (movingUp) {
			sprite->move(0, scrollSpeed * dT);
		}

		if (movingDown) {
				sprite->move(0, -scrollSpeed * dT);
		}
	}
}


void MapRenderer::render(sf::RenderWindow& window)
{
	for (int i = 0; i < map->getSize(); i++) {

		//map->getTileAt(i)->render(window);
		sf::Sprite* sprite = map->getTileAt(i)->getSprite();
		
		sf::Vector2f pos = sprite->getPosition();

		window.draw(*sprite);
	}

}

void MapRenderer::moveLeft(bool movingLeft){
	this->movingLeft = movingLeft;
}

void MapRenderer::moveRight(bool movingRight){
	this->movingRight = movingRight;
}

void MapRenderer::moveUp(bool movingUp) {
	this->movingUp = movingUp;
}

void MapRenderer::moveDown(bool movingDown) {
	this->movingDown = movingDown;
}
MapRenderer::~MapRenderer()
{
}
