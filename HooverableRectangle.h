#ifndef HOOVERABLERECTANGLE_H
#define HOOVERABLERECTANGLE_H

#include <iostream>
#include "Hooverable.h"
#include "SFML/Graphics.hpp"

class HooverableRectangle : public HooverAble {
private:

	sf::RenderWindow* window = nullptr;

public:

	HooverableRectangle(const sf::Vector2f size);

	void setPosition(sf::Vector2f pos);
	void render(sf::RenderWindow& window);
	sf::RectangleShape* getRectangleShape();
	void update(long dT);
	void hooverAction();

	~HooverableRectangle() {}
};

#endif // !HOOVERABLERECTANGLE_H


