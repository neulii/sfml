#include "MapRenderer.h"

MapRenderer::MapRenderer(GameMap& map, int windowWidth, int windowHeight)
{
	this->map = &map;
	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;
}

void MapRenderer::update(long dT)
{
	sf::Sprite* sprite = NULL;

	//moving left
	if (movingLeft && !mapIsOnLeftBorder) {

		for (int i = 0; i < map->getSize(); i++) {

			sprite = map->getTileAt(i)->getSprite();
			sprite->move(scrollSpeed * dT, 0);

		}

		mapIsOnRightBorder = false;

		if (map->getTileAt(0)->getSprite()->getPosition().x > 0) {
			mapIsOnLeftBorder = true;

		}
	}

	//moving right
	if (movingRight && !mapIsOnRightBorder) {
		for (int i = 0; i < map->getSize(); i++) {
			sprite = map->getTileAt(i)->getSprite();
			sprite->move(-scrollSpeed * dT, 0);

		}

		mapIsOnLeftBorder = false;

		if (map->getTileAt(map->getSize() - 1)->getSprite()->getPosition().x + sprite->getTextureRect().width <= windowWidth) {
			mapIsOnRightBorder = true;
		}
	}

	//moving up
	if (movingUp && !mapIsOnTopBorder) {
		for (int i = 0; i < map->getSize(); i++) {
			sprite = map->getTileAt(i)->getSprite();
			sprite->move(0, scrollSpeed * dT);

		}

		mapIsOnBottomBorder = false;

		if (map->getTileAt(0)->getSprite()->getPosition().y >= 0) {
			mapIsOnTopBorder = true;
		}
	}

	//moving down
	if (movingDown && !mapIsOnBottomBorder) {
		for (int i = 0; i < map->getSize(); i++) {
			sprite = map->getTileAt(i)->getSprite();
			sprite->move(0, -scrollSpeed * dT);
		}

		mapIsOnTopBorder = false;

		if (map->getTileAt(map->getSize() - 1)->getSprite()->getPosition().y + sprite->getTextureRect().height <= windowHeight) {
			mapIsOnBottomBorder = true;
		}
	}

	//render border in mouse hoovered tile

	ProductionTile* hooveredTile = map->getTileAt(mousePos);

	hooveredTile->


}


void MapRenderer::render(sf::RenderWindow & window)
{
	for (int i = 0; i < map->getSize(); i++) {

		//map->getTileAt(i)->render(window);
		sf::Sprite* sprite = map->getTileAt(i)->getSprite();

		sf::Vector2f pos = sprite->getPosition();

		window.draw(*sprite);
	}

}

void MapRenderer::moveLeft(bool movingLeft) {
	this->movingLeft = movingLeft;
}

void MapRenderer::moveRight(bool movingRight) {
	this->movingRight = movingRight;
}

void MapRenderer::moveUp(bool movingUp) {
	this->movingUp = movingUp;
}

void MapRenderer::moveDown(bool movingDown) {
	this->movingDown = movingDown;
}

void MapRenderer::setMousePos(sf::Vector2f mousePos) {
	this->mousePos = mousePos;
	//cout << mousePos.x << "  /  " << mousePos.y << endl;


}
MapRenderer::~MapRenderer()
{
}