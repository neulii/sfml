#pragma once
#include "GameObject.h"
class MenuButton : public GameObject
{
public:
	MenuButton();

	void render(sf::RenderWindow& window);
	void update(long dT);


	~MenuButton();
};

