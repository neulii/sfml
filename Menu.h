#ifndef MENU_H
#define MENU_H

#include "MenuButton.h"
#include "GameObject.h"
class Menu : public GameObject
{

private:
	std::vector<MenuButton*> menuButtons;
	int distanceTop = 100;
	int distanceBetween = 10;

	sf::Vector2f mousePos;
	sf::RenderWindow *window;

public:
	Menu(sf::RenderWindow &window);

	void update(long dT);
	void render(sf::RenderWindow& window);
	void addMenuButton(string text, float width, float height);
	void setDistanceBetween(int distance);
	void setDistanceTop(int distance);
	void setMousePos(sf::Vector2f);
	string clicked();
	void mouseRelease();

	~Menu();
};

#endif // !MENU_H


