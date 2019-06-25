#include "Functions.hpp"
#include <iostream>
#include "SFML/Graphics.hpp"

void drawColorToConsole(sf::Color color) {

	std::cout << (int) color.r << "    " << (int)color.g << "   " << (int)color.b << std::endl;

}
