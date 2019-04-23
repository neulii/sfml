#include "MenuButton.h"
#include <iostream>

void MenuButton::render(sf::RenderWindow& window) {

	window.draw(buttonShape);
	window.draw(this->buttonText);
}
void MenuButton::update(long dT) {

}

MenuButton::MenuButton(string buttonText, float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->height = height;
	this->width = width;

	if (!buttonFont.loadFromFile("arial.ttf")) {
		std::cout << "Fehler beim Laden der button-Schrift";

	}
	else
		std::cout << "button-Schrift geladen";

	isHoovered = false;

	drawBackgroundcolor = normalBackgroundColor;
	drawTextColor = normalBackgroundColor;

	buttonShape.setSize(sf::Vector2f(width, height));
	buttonShape.setPosition(sf::Vector2f(x, y));
	buttonShape.setFillColor(normalBackgroundColor);
	/*buttonShape.setOutlineThickness(1);
	buttonShape.setOutlineColor(sf::Color::Red);*/

	this->buttonText.setFont(buttonFont);
	this->buttonText.setString(buttonText);
	this->buttonText.setCharacterSize(20);
	this->buttonText.setPosition(x + (width - this->buttonText.getLocalBounds().width) / 2, y + (height - this->buttonText.getLocalBounds().height) / 2);
	this->buttonText.setFillColor(normalTextColor);

	std::cout << this->buttonText.getLocalBounds().width  << " / " <<  this->buttonText.getLocalBounds().height << endl;
}


MenuButton::~MenuButton()
{
}
