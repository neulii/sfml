#include "Menu.h"
#include <iostream>

Menu::Menu(sf::RenderWindow &window)
{
	this->window = &window;
	this->mousePos = sf::Vector2f(0, 0);
}

void Menu::update(long dT)
{
	for (MenuButton &button : menuButtons)
	{
		if (button.getButtonBounds().contains(this->mousePos)) {
			button.setHoovered(true);
		}

		else
		{
			button.setHoovered(false);
			button.setPressed(false);
		}
	}
}

void Menu::setMousePos(sf::Vector2f mousePos) {
	this->mousePos = mousePos;
}

void Menu::render(sf::RenderWindow& window)
{
	for(MenuButton &button: menuButtons)
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
