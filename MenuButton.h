#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include "GameObject.h"

using namespace std;

class MenuButton : public GameObject
{

private:

	float x;
	float y;
	float width;
	float height;

	float buttonTextPosX;
	float buttonTextPosY;

	bool isHoovered = false;
	bool isPressed = false;

	sf::Color normalTextColor = sf::Color::White;
	sf::Color normalBackgroundColor = sf::Color(160, 160, 160);

	sf::Color drawTextColor;
	sf::Color drawBackgroundcolor;

	sf::Color hooverTextColor = sf::Color::Black;
	sf::Color hooverBackgroundColor = sf::Color(52,124,239);

	sf::Text buttonText;
	sf::Font buttonFont;

	sf::RectangleShape buttonShape;

public:
	
	MenuButton(string buttonText, float x, float y, float height, float width);

	sf::FloatRect getButtonBounds();
	void render(sf::RenderWindow& window);
	void update(long dT);
	void setHoovered(bool hoovered);
	void setPressed(bool pressed);
	bool getIsHoovered();

	~MenuButton();
};

#endif // !MENUBUTTON_H