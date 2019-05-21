#include "MapRenderer.h"

MapRenderer::MapRenderer(GameMap &map, sf::RenderWindow &window)
{
	this->map = &map;
	this->window = &window;
}

void MapRenderer::update(long dT)
{

	sf::Sprite* sprite;

		if (movingLeft && !mapIsOnRightBorder) {
				
			for (int i = 0; i < map->getSize(); i++) {

				sprite = map->getTileAt(i)->getSprite();
				sprite->move(scrollSpeed * dT, 0);

			}

			mapIsOnLeftBorder = false;

			if (map->getTileAt(map->getSize() - 1)->getSprite()->getPosition().x + sprite->getTextureRect().width >= window->getSize().x) {
				mapIsOnRightBorder = true;
			}

		}

		if (movingRight && !mapIsOnLeftBorder) {	
			for (int i = 0; i < map->getSize(); i++) {
				sprite = map->getTileAt(i)->getSprite();
				sprite->move(-scrollSpeed * dT, 0);

			}

			mapIsOnRightBorder = false;
			
			if (map->getTileAt(0)->getSprite()->getPosition().x < 0) {
				mapIsOnLeftBorder = true;

			}

		}

		if (movingUp) {
			for (int i = 0; i < map->getSize(); i++) {
				sprite = map->getTileAt(i)->getSprite();
				sprite->move(0, scrollSpeed * dT);

			}
		}

		if (movingDown) {
			for (int i = 0; i < map->getSize(); i++) {
				sprite = map->getTileAt(i)->getSprite();
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
