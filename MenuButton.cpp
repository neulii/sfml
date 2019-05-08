#include "MenuButton.h"
#include <iostream>
#include "Functions.hpp"

void MenuButton::render(sf::RenderWindow& window) {
	sf::RectangleShape shadow;
	shadow.setPosition(x-2, y-2);
	shadow.setFillColor(sf::Color::Yellow);
	shadow.setSize(sf::Vector2f(width, height));

	switch (isHoovered)
	{
	case true:
		
		this->drawBackgroundcolor = this->hooverBackgroundColor;
		this->drawTextColor = this->hooverTextColor;
		
		break;

	case false:

		this->drawBackgroundcolor = this->normalBackgroundColor;
		this->drawTextColor = this->normalTextColor;
		break;
	}

	if (isPressed) {
		buttonShape.setPosition(x - 2, y -2);
		buttonText.setPosition(buttonTextPosX - 2, buttonTextPosY - 2);
	}
	else {
		buttonShape.setPosition(x, y);
		buttonText.setPosition(buttonTextPosX, buttonTextPosY);
	}

	buttonShape.setFillColor(drawBackgroundcolor);
	buttonText.setFillColor(drawTextColor);
	
	window.draw(shadow);
	window.draw(buttonShape);
	window.draw(this->buttonText);
}
void MenuButton::update(long dT) {

}

void MenuButton::setHoovered(bool hoovered) {
	this->isHoovered = hoovered;
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
		std::cout << "Button-Font from button \"" << buttonText << "\" loaded" << std::endl;

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
	this->buttonTextPosX = x + (width - this->buttonText.getLocalBounds().width) / 2;
	this->buttonTextPosY = y + (height - this->buttonText.getLocalBounds().height) / 2;
	this->buttonText.setPosition(buttonTextPosX,buttonTextPosY);
	this->buttonText.setFillColor(normalTextColor);
}

MenuButton::~MenuButton()
{
}

sf::FloatRect MenuButton::getButtonBounds() {
	return buttonShape.getGlobalBounds();
}

void MenuButton::setPressed(bool pressed) {
	this->isPressed = pressed;
}

bool MenuButton::getIsHoovered(){
	return isHoovered;
}

bool MenuButton::getIsPressed() {
	return this->isPressed;
}

string MenuButton::getButtonText() {
	return this->buttonText.getString();
}