#ifndef HOOVERABLE_H
#define HOOVERABLE_H

#include "SFML/Graphics.hpp"

class HooverAble {

protected:

	bool isHoovered = false;
	sf::Color hooverBackgroundColor = sf::Color(52, 124, 239);

public: 

	virtual void setHoovered(bool hoovered);
	virtual void render(sf::RenderWindow& window) = 0;







};





#endif
