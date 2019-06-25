#ifndef HOOVERABLE_H
#define HOOVERABLE_H

#include <SFML/Graphics.hpp>


class HooverAble {

private:
	bool isHoovered = false;

protected:
	sf::RectangleShape rec;

public:
	virtual void render(sf::RenderWindow& window) = 0;
	virtual void update(long dT) = 0;
	virtual void hooverAction() = 0;

	bool getIsHoovered();

	void setIsHoovered(bool isHoovered);

	virtual ~HooverAble() {}

};




#endif // ! HOOVERABLE_H

