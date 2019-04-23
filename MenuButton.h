#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include "GameObject.h"

using namespace std;

class MenuButton : public GameObject
{

private:

	float x;
	float y;
	float width;
	float height;

	bool isHoovered;

	
	sf::Text buttonText;
	sf::Font buttonFont;

	sf::RectangleShape buttonShape;





public:
	
	MenuButton(string buttonText, float x, float y, float height, float width);

	void render(sf::RenderWindow& window);
	void update(long dT);



	~MenuButton();
};


#endif // !MENUBUTTON_H



