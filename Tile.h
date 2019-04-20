#pragma once
#include "GameObject.h"
#include "FieldType.h"
class Tile : public GameObject
{
	private: 

		int x;
		int y;
		int width;
		int height;

		sf::Texture texture;

		FieldType fieldType;


	public:
		Tile(FieldType fieldType, int x, int y, int width, int height, sf::Texture texture);

		void render(sf::RenderWindow &window);
		void update(long dT);
	
		~Tile();
	};

