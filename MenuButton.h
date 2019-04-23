#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include "GameObject.h"
class MenuButton : public GameObject
{
public:
	MenuButton();

	void render(sf::RenderWindow& window);
	void update(long dT);


	~MenuButton();
};


#endif // !MENUBUTTON_H



