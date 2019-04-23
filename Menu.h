#ifndef MENU_H
#define MENU_H

#include "MenuButton.h"
#include "GameObject.h"
class Menu : public GameObject
{

private:
	std::vector<MenuButton> menuButtons;
	int distanceTop = 200;
	int distanceBetween = 50;

public:
	Menu();

	void update(long dT);
	void render(sf::RenderWindow& window);
	void addMenuButton(MenuButton button);
	void setDistanceBetween(int distance);
	void setDistanceTop(int distance);
	
	~Menu();
};

#endif // !MENU_H


