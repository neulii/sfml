#ifndef GAMEOBJECT_H
#include <SFML/Graphics.hpp>

class GameObject
{
public:

	
	virtual void update(long dT) = 0;
	virtual void render(sf::RenderWindow) = 0;

};

#endif // !GAMEOBJECT_H


