#ifndef MENU_H
#define MENU_H

#include "MenuButton.h"
#include "GameObject.h"
class Menu : public GameObject
{

private:
	std::vector<MenuButton> menuButtons;


public:
	Menu(int x, int y);

	void update(long dT);
	void render(sf::RenderWindow& window);
	
	void addMenuButton(MenuButton button);
	
	~Menu();
};

#endif // !MENU_H


