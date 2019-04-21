#include <SFML/Graphics.hpp>

#include <iostream>
#include "Functions.hpp"
#include "Tile.h"
#include "FieldType.h"

int game() {
   

	
    sf::Time time;
    
	//create window
	sf::RenderWindow window(sf::VideoMode(800,600),"steelManager",sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    
	sf::Texture coalField;
	if (!coalField.loadFromFile("images/coalField.png")) {
		std::cout << "Fehler beim Laden des bildes" << std::endl;

	}
	
	Tile tile(FieldType::coalField, 100, 100,10, 10, coalField);

    

    sf::Clock dT;
    
    sf::CircleShape circle(20);
	circle.setFillColor(sf::Color::Red);
    
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
        
        //std::cout << time.asMicroseconds() << std::endl;
        
        //update game logic
      
        dT.restart();
        
        //clear screen
        window.clear();
        
       
        
      
        //draw objects
        
		tile.render(window);

		
        window.draw(circle);
        
		
        
        window.display();
    }
    
    return EXIT_SUCCESS ;
}



