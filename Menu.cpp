#include "Menu.h"

Menu::Menu()
{
}

void Menu::update(long dT)
{
}

void Menu::render(sf::RenderWindow& window)
{
	for each (MenuButton button in menuButtons)
	{
		button.render(window);
	}
}

void Menu::addMenuButton(MenuButton menuButton) {
	menuButtons.push_back(menuButton);
}

void Menu::setDistanceTop(int distance) {
	this->distanceTop = distance;
}

void Menu::setDistanceBetween(int distance){
	this->distanceBetween = distance;
}

Menu::~Menu()
{
}
