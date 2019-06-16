#include <iostream>
#include "Functions.hpp"
#include "Tile.h"
#include "FieldType.h"
#include "GameState.h"
#include "MenuButton.h"
#include "Menu.h"
#include "StringMap.h"
#include "ProductionTile.h"
#include <set>
#include "Types.h"
#include "GameMap.h"
#include "MapRenderer.h"


class HooverAble {

private: 
	bool isHoovered = false;
    
protected:
    sf::RectangleShape rec;

public:
	virtual void render(sf::RenderWindow &window) = 0;
	virtual void update(long dT) = 0;
	virtual void hooverAction() = 0;
	
	bool getIsHoovered() {
		return this->isHoovered;
	}

	void setIsHoovered(bool isHoovered){
		this->isHoovered = isHoovered;
	}

	virtual ~HooverAble(){}

};

class HooverableRectangle : public HooverAble{
private:
	
	sf::RenderWindow *window = nullptr;

public:

	HooverableRectangle(const sf::Vector2f size)  {
		rec.setSize(size);
	}
    
    void setPosition(sf::Vector2f pos){
      
        rec.setPosition(pos);
        
    }

	void render(sf::RenderWindow& window) {
		this->window = &window;
		window.draw(rec);
	}

	sf::RectangleShape* getRectangleShape(){
		return &rec;
	}

	void update(long dT) {
        if(window!=nullptr){
			//std::cout << sf::Mouse::getPosition().x-window->getPosition().x << "   " << sf::Mouse::getPosition().y - window->getPosition().y << std::endl;
            
            float relativeMousePosX = static_cast<float>(sf::Mouse::getPosition().x-window->getPosition().x);
            float relativeMousePosY = static_cast<float>(sf::Mouse::getPosition().y-window->getPosition().y);
            
            
    //        std::cout << rec.getLocalBounds().left << "     "  << rec.getLocalBounds().top << std::endl;
    //        std::cout << rec.getSize().x << "   " << rec.getSize().y << std::endl;
            
            if (rec.getLocalBounds().contains(relativeMousePosX, relativeMousePosY)){
    //        if(rec.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)){
            
            std::cout << "hoovered"<< std::endl;
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

	void hooverAction() {
		std::cout << "is hoovered" << std::endl;

	}

	~HooverableRectangle(){}
	
};

void loadTextures();
void startNewGame();

int windowWidth = 800;
int windowHeight = 600;

sf::RenderWindow* window;
sf::Texture menuBackgroundTexture;

sf::Texture grassFieldTexture;

sf::Texture coalMineFieldTexture;
sf::Texture coalFieldTexture;

sf::Texture ironOreFieldTexture;
sf::Texture ironOreMineFieldTexture;

sf::Texture furnaceFieldTexture;

FieldTextureMap fieldTextureMap;

GameState gameState = GameState::titleMenu;

StringMap stringMap(100, 100);

vector<int> myMap{ 0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
				   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
				   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
				   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
				   4,2,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
				   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
				   0,5,0,0,0,0,3,0,0,0,0,0,1,0,0,0,0,0,0,0,
				   0,0,0,0,0,0,3,0,0,0,0,0,1,0,0,0,0,0,0,0,
				   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
				   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
				   0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
				   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
				   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
				   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
				   4,2,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
				   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
				   0,5,0,0,0,0,3,0,0,0,0,0,1,0,0,0,0,0,0,0,
				   0,0,0,0,0,0,3,0,0,0,0,0,1,0,0,0,0,0,0,0,
				   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
				   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
};

StringMap myStringMap(20, 20, myMap);

GameMap* gameMap;
MapRenderer* mapRenderer;

//counter from TileClass
unsigned Tile::tileCounter = 0;

int main() {

	HooverableRectangle button(sf::Vector2f(50, 50));
    button.setPosition(sf::Vector2f(0,0));



	





	//create window
	window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "steelManager", /*sf::Style::Titlebar |*/ sf::Style::None);
	window->setFramerateLimit(60);		//set frame limit to 60 fps
	
	//laden der texturen
	loadTextures();


	//Menue erstellen
	Menu titleMenu(*window);
	titleMenu.setBackground(menuBackgroundTexture);
	titleMenu.addMenuButton("Neues Spiel", 150, 50);
	titleMenu.addMenuButton("Spiel Laden", 150, 50);
	titleMenu.addMenuButton("Spiel Beenden", 150, 50);

	sf::Time time;
	sf::Clock dT;

	//Gameloop
	while (window->isOpen()) {
		sf::Event event;

		//umwandlung von int in float
		sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
		sf::Vector2f mousePosF = sf::Vector2f(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

		string clickedButton = "none";

		while (window->pollEvent(event)) {

			switch (event.type) {
			case sf::Event::Closed:

				window->close();
				break;


				//Mouse moved
			case sf::Event::MouseMoved:
				switch (gameState) {
				case GameState::playing:

					mapRenderer->setMousePos(mousePosF);


					break;

				case GameState::titleMenu:
					titleMenu.setMousePos(mousePosF);

					break;

				}

				break;
				//mouse button pressed
			case sf::Event::MouseButtonPressed:

				switch (gameState)
				{
				case GameState::titleMenu:

					clickedButton = titleMenu.clicked();

					//Neues Spiel starten
					if (clickedButton == "Neues Spiel") {
						startNewGame();

					}

					//Spiel Laden
					if (clickedButton == "Spiel Laden") {


					}

					//Spiel beenden
					if (clickedButton == "Spiel Beenden") {
						exit(0);
					}

					break;

				case GameState::playing:
					cout << "button clicked" << endl;

					break;
				default:
					break;
				}


				break;

				//mouse button released
			case sf::Event::MouseButtonReleased:

				switch (gameState) {
				case GameState::playing:
					cout << "button released" << endl;
					break;

				case GameState::titleMenu:
					titleMenu.mouseRelease();
					break;
				}


				break;
			}
		}

		time = dT.getElapsedTime();
		long timeElapsed = time.asMilliseconds();

		//check key's

		switch (gameState) {

			//wile Ingame
		case GameState::playing:

			//LEFT
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				mapRenderer->moveLeft(true);
			}
			else {
				mapRenderer->moveLeft(false);
			}

			//Right
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				mapRenderer->moveRight(true);
			}
			else
				mapRenderer->moveRight(false);

			//Up
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				mapRenderer->moveUp(true);
			}
			else
				mapRenderer->moveUp(false);

			//Down
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				mapRenderer->moveDown(true);
			}
			else
				mapRenderer->moveDown(false);

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                    gameState = GameState::titleMenu;
                }
			break;
		}

		//update game logic
		dT.restart();		//restart clock

		switch (gameState)
		{

		case GameState::titleMenu:

			window->clear();
			titleMenu.update(timeElapsed);


			break;

		case GameState::playing:
			button.update(timeElapsed);
			
			//std::cout << window->getPosition().x << std::endl;
			window->clear();
			mapRenderer->update(timeElapsed);

			break;

		case GameState::pausedMenu:

			break;

		default:
			break;
		}




		//rendering objects
		switch (gameState)
		{

		case GameState::titleMenu:

			titleMenu.render(*window);

			break;

		case GameState::playing:
			mapRenderer->render(*window);
			button.render(*window);

			break;

		case GameState::pausedMenu:

			break;

		default:
			break;
		}



		window->display();
	}

	return EXIT_SUCCESS;
}

//lade texturen
void loadTextures() {

	cout << "Loading textures ";

	//background titlemenu
	menuBackgroundTexture.loadFromFile("images/steel_background.jpg");
	cout << ".";
	//fieldtexutres
	grassFieldTexture.loadFromFile("images/grassField.png");
	cout << ".";
	coalFieldTexture.loadFromFile("images/coalField.png");
	cout << ".";
	coalMineFieldTexture.loadFromFile("images/coalMineField.png");
	cout << ".";
	ironOreFieldTexture.loadFromFile("images/iron_oreField.png");
	cout << ".";
	ironOreMineFieldTexture.loadFromFile("images/ironOreMineField.png");
	cout << ".";
	furnaceFieldTexture.loadFromFile("images/furnaceField.png");
	cout << ".";

	fieldTextureMap.insert(make_pair(0, grassFieldTexture));
	fieldTextureMap.insert(make_pair(1, coalFieldTexture));
	fieldTextureMap.insert(make_pair(2, coalMineFieldTexture));
	fieldTextureMap.insert(make_pair(3, ironOreFieldTexture));
	fieldTextureMap.insert(make_pair(4, ironOreMineFieldTexture));
	fieldTextureMap.insert(make_pair(5, furnaceFieldTexture));

}

//neues spiel starten
void startNewGame() {


	std::cout << "create GameMap" << endl;
	gameMap = new GameMap(myStringMap, fieldTextureMap);
	std::cout << "gameMap created   " << endl;

	mapRenderer = new MapRenderer(*gameMap, windowWidth, windowHeight);
	gameState = GameState::playing;
}
