#ifndef TILE_H
#define TilE_H

#include "GameObject.h"
#include "FieldType.h"
class Tile : public GameObject
{
	private: 

		int x;
		int y;
		int width;
		int height;

		sf::RectangleShape rect;

		sf::Texture texture;
		sf::Sprite tileSprite;

		//FieldType fieldType;

	public:
		//Tile(FieldType fieldType, int x, int y, sf::Texture texture);
		Tile(int x, int y, sf::Texture texture);
		void render(sf::RenderWindow &window);
		void update(long dT);
	
		~Tile();
	};

#endif // !TILE_H

