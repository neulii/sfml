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
#include "Hooverable.h"
#include "HooverableRectangle.h"

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
					//cout << "button clicked" << endl;

					break;
				default:
					break;
				}


				break;

				//mouse button released
			case sf::Event::MouseButtonReleased:

				switch (gameState) {
				case GameState::playing:
					//cout << "button released" << endl;
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
	menuBackgroundTexture.loadFromFile("resources/images/steel_background.jpg");
	cout << ".";
	//fieldtexutres
	grassFieldTexture.loadFromFile("resources/images/grassField.png");
	cout << ".";
	coalFieldTexture.loadFromFile("resources/images/coalField.png");
	cout << ".";
	coalMineFieldTexture.loadFromFile("resources/images/coalMineField.png");
	cout << ".";
	ironOreFieldTexture.loadFromFile("resources/images/iron_oreField.png");
	cout << ".";
	ironOreMineFieldTexture.loadFromFile("resources/images/ironOreMineField.png");
	cout << ".";
	furnaceFieldTexture.loadFromFile("resources/images/furnaceField.png");
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
