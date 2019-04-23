#include <iostream>
#include "Functions.hpp"
#include "Tile.h"
#include "FieldType.h"
#include "GameState.h"
#include "MenuButton.h"

int main() {
	
	
	MenuButton button("Spiel starten", 100,100,100,20); 

	GameState gameState = GameState::titleMenu;

	
	
	
	
	
	
   
    sf::Time time;
    
	//create window
	sf::RenderWindow window(sf::VideoMode(800,600),"steelManager",sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);		//set frame limit to 60 fps
    

    sf::Clock dT;


    
    while (window.isOpen()) {
        sf::Event event;
      
        while(window.pollEvent(event)){
            switch (event.type){
                case sf::Event::Closed:
                    
                    window.close();
                    break;
      

            }
        }
        
        time = dT.getElapsedTime();
        long timeElapsed = time.asMilliseconds();
        
     
        
        //update game logic
        dT.restart();		//restart clock 
        

        window.clear();		//clear screen
       
        //draw objects
		
		switch (gameState)
		{

		case GameState::titleMenu:

			button.render(window);
		
			break;
		
		default:
			break;
		}


       
        window.display();
    }
    
    return EXIT_SUCCESS ;
}