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

void loadTextures();
void startNewGame();

sf::Texture menuBackgroundTexture;
sf::Texture grassFieldTexture;
sf::Texture coalFieldTexture;
sf::Texture ironOreFieldTexture;
sf::Texture ironOreMineFieldTexture;

FieldTextureMap fieldTextureMap;


GameState gameState = GameState::titleMenu;


StringMap stringMap(10,10);
GameMap *gameMap;
MapRenderer *mapRenderer;


int main() {

	//create window
	sf::RenderWindow window(sf::VideoMode(800,600),"steelManager",sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);		//set frame limit to 60 fps
    
	//laden der texturen
	loadTextures();
	gameMap = new GameMap(stringMap, fieldTextureMap);
	mapRenderer = new MapRenderer(*gameMap);
	ProductionTile test(FieldType::coalMineField, 100, 100, ironOreMineFieldTexture);

	//Menue erstellen
	Menu titleMenu(window);
	titleMenu.setBackground(menuBackgroundTexture);
	titleMenu.addMenuButton("Neues Spiel", 150, 50);
	titleMenu.addMenuButton("Spiel Laden", 150, 50);
	titleMenu.addMenuButton("Spiel Beenden", 150, 50);
	
    sf::Time time;
    sf::Clock dT;

	//Gameloop
    while (window.isOpen()) {
        sf::Event event;
      
		//umwandlung von int in float
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		sf::Vector2f mousePosF = sf::Vector2f(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

		string clickedButton = "none";

        while(window.pollEvent(event)){
            switch (event.type){
                case sf::Event::Closed:
                    
                    window.close();
                    break;
      
				case sf::Event::MouseMoved:

					titleMenu.setMousePos(mousePosF);

					break;

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
					default:
						break;
					}

				
					break;
				
				case sf::Event::MouseButtonReleased:

					titleMenu.mouseRelease();
					
					break;
            }
        }
        
        time = dT.getElapsedTime();
        long timeElapsed = time.asMilliseconds();
        
     
  
        //update game logic
        dT.restart();		//restart clock 
		

		titleMenu.update(timeElapsed);

        window.clear();		//clear screen
       
        //rendering objects
		
		switch (gameState)
		{

		case GameState::titleMenu:

			titleMenu.render(window);
		
			break;

		case GameState::playing:
			mapRenderer->render(window);
			test.render(window);

			

			break;

		case GameState::pausedMenu:

			break;
		
		default:
			break;
		}


       
        window.display();
    }
    
    return EXIT_SUCCESS ;
}

//lade texturen
void loadTextures() {
	cout << "Loading textures ";
	menuBackgroundTexture.loadFromFile("images/steel_background.jpg");
	cout << ".";
	grassFieldTexture.loadFromFile("images/grassField.png");
	cout << ".";
	coalFieldTexture.loadFromFile("images/coalField.png");
	cout << ".";
	ironOreFieldTexture.loadFromFile("images/iron_oreField.png");
	cout << ".";
	ironOreMineFieldTexture.loadFromFile("images/ironOreMineField.png");
	cout << ".";

	fieldTextureMap.insert(make_pair(0,grassFieldTexture));
	fieldTextureMap.insert(make_pair(1, coalFieldTexture));
	fieldTextureMap.insert(make_pair(2, ironOreFieldTexture));


}

//neues spiel starten
void startNewGame() {

	gameState = GameState::playing;
}

