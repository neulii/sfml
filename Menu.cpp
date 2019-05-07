#include "Menu.h"
#include <iostream>

Menu::Menu(sf::RenderWindow &window)
{
	this->window = &window;
	this->mousePos = sf::Vector2f(0, 0);
}

void Menu::update(long dT)
{
	for (MenuButton *button : menuButtons)
	{
		if (button->getButtonBounds().contains(this->mousePos)) {
			button->setHoovered(true);
		}

		else
		{
			button->setHoovered(false);
			button->setPressed(false);
		}
	}
}

void Menu::setMousePos(sf::Vector2f mousePos) {
	this->mousePos = mousePos;
}

void Menu::clicked() {
	for (MenuButton* button : menuButtons) {
		
		if (button->getIsHoovered()) {
			button->setPressed(true);

		}
	}
}

void Menu::mouseRelease() {
	for (MenuButton* button : menuButtons) {

		if (button->getIsHoovered() && button->getIsPressed()) {
			button->setPressed(false);
		}
	}
}

void Menu::render(sf::RenderWindow& window)
{
	for(MenuButton *button: menuButtons)
	{
		button->render(window);
	}
}

void Menu::addMenuButton(string text, float width, float height) {
	
	menuButtons.push_back(new MenuButton(text, (window->getSize().x-width) / 2, distanceTop + menuButtons.size()*(height+distanceBetween), width, height));
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
