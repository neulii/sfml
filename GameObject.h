#ifndef GAMEOBJECT_H
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	virtual void update(long dT);
	virtual void render(sf::RenderWindow);

};

#endif // !GAMEOBJECT_H


