#include <iostream>
#include "Functions.hpp"
#include "Tile.h"
#include "FieldType.h"
#include "GameState.h"
#include "MenuButton.h"
#include "Menu.h"

int main() {
	
	//create window
	sf::RenderWindow window(sf::VideoMode(800,600),"steelManager",sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);		//set frame limit to 60 fps
    
	
	MenuButton button("Spiel starten", 100,100,150,40);
	MenuButton button2("Spiel beenden", 100, 150, 150, 40);

	GameState gameState = GameState::titleMenu;
	Menu titleMenu(window);

	titleMenu.addMenuButton("super spiel", 150, 50);
	titleMenu.addMenuButton("coo", 150, 50);
	titleMenu.addMenuButton("alskdjfalsd", 150, 50);
	titleMenu.addMenuButton("asdf", 150, 50);
	titleMenu.addMenuButton("alskdjfalssdfd", 150, 50);
	titleMenu.addMenuButton("asdf", 150, 50);
	


    sf::Time time;
    
    sf::Clock dT;

    while (window.isOpen()) {
        sf::Event event;
      
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		sf::Vector2f mousePosF = sf::Vector2f(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

        while(window.pollEvent(event)){
            switch (event.type){
                case sf::Event::Closed:
                    
                    window.close();
                    break;
      
				case sf::Event::MouseMoved:

					titleMenu.setMousePos(mousePosF);

					break;

				case sf::Event::MouseButtonPressed:

					titleMenu.clicked();
				
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
		button.update(timeElapsed);

		titleMenu.update(timeElapsed);

        window.clear();		//clear screen
       
        //draw objects
		
		switch (gameState)
		{

		case GameState::titleMenu:

			titleMenu.render(window);
		
			break;
		
		default:
			break;
		}


       
        window.display();
    }
    
    return EXIT_SUCCESS ;
}