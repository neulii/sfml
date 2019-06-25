#include "HooverableRectangle.h"

HooverableRectangle::HooverableRectangle(const sf::Vector2f size) {
	rec.setSize(size);
}

void HooverableRectangle::setPosition(sf::Vector2f pos) {

	rec.setPosition(pos);

}

void HooverableRectangle::render(sf::RenderWindow& window) {
	this->window = &window;
	window.draw(rec);
}

sf::RectangleShape* HooverableRectangle::getRectangleShape() {
	return &rec;
}

void HooverableRectangle::update(long dT) {
	if (window != nullptr) {
		//std::cout << sf::Mouse::getPosition().x-window->getPosition().x << "   " << sf::Mouse::getPosition().y - window->getPosition().y << std::endl;

		float relativeMousePosX = static_cast<float>(sf::Mouse::getPosition().x - window->getPosition().x);
		float relativeMousePosY = static_cast<float>(sf::Mouse::getPosition().y - window->getPosition().y);

		if (rec.getLocalBounds().contains(relativeMousePosX, relativeMousePosY)) {

			//std::cout << "hoovered" << std::endl;
			setIsHoovered(true);

		}
		else {
			setIsHoovered(false);
		}

		if (HooverAble::getIsHoovered()) {
			rec.setOutlineThickness(5);
			hooverAction();
		}
		else {
			rec.setOutlineThickness(0);

		}

	}
}

void HooverableRectangle::hooverAction() {
	//std::cout << "is hoovered" << std::endl;

}
