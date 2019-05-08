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

string Menu::clicked() {
	string buttonClicked = "none";

	for (MenuButton* button : menuButtons) {
		
		if (button->getIsHoovered()) {
			button->setPressed(true);
			buttonClicked = button->getButtonText();
		}
	}

	return buttonClicked;

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
	unsigned int windowWidth = window.getSize().x;
	unsigned int windowHeight = window.getSize().y;

	unsigned int textureWidth = backgroundTex.getSize().x;
	unsigned int textureHeight = backgroundTex.getSize().y;

	float scaleX =  windowWidth*1.0f/ textureWidth;
	float scaleY =  windowHeight*1.0f/ textureHeight;

	backgroundSprite.setTexture(backgroundTex);
	backgroundSprite.setScale(scaleX, scaleY);
	window.draw(this->backgroundSprite);

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

void Menu::setBackground(sf::Texture &texture) {
	this->backgroundTex = texture;
}

Menu::~Menu()
{
}
