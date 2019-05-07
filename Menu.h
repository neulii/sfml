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

	sf::Vector2f mousePos;
	sf::RenderWindow *window;

public:
	Menu(sf::RenderWindow &window);

	void update(long dT);
	void render(sf::RenderWindow& window);
	void addMenuButton(MenuButton button);
	void setDistanceBetween(int distance);
	void setDistanceTop(int distance);
	void setMousePos(sf::Vector2f);

	~Menu();
};

#endif // !MENU_H


