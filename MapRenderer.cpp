#include "MapRenderer.h"

MapRenderer::MapRenderer(GameMap &map)
{
	this->map = &map;

}

void MapRenderer::update(long dT)
{
}
void MapRenderer::render(sf::RenderWindow& window)
{
	for (int i = 0; i < map->getSize(); i++) {

		map->getTileAt(i)->render(window);

	}

}


MapRenderer::~MapRenderer()
{
}
