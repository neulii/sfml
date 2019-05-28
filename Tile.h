#ifndef TILE_H
#define TILE_H

#include "GameObject.h"
#include "FieldType.h"
class Tile : public GameObject
{
	private: 

		static unsigned tileCounter;

		double x;
		double y;
		int width;
		int height;

		sf::RectangleShape rect;

		sf::Texture *texture;
		sf::Sprite tileSprite;

		//FieldType fieldType;

	public:
		//Tile(FieldType fieldType, int x, int y, sf::Texture texture);
		Tile(double x, double y, sf::Texture &texture);
		void render(sf::RenderWindow &window);
		void update(long dT);
		bool contains(sf::Vector2f pos);
		sf::Sprite* getSprite();
		~Tile();
	};

#endif // !TILE_H

