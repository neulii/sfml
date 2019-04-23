#include <iostream>
#include "Functions.hpp"
#include "Tile.h"
#include "FieldType.h"
#include "GameState.h"
#include "MenuButton.h"

int main() {
	
	
	MenuButton button("Spiel starten", 100,100,150,40);
	MenuButton button2("Spiel beenden", 100, 150, 150, 40);

	GameState gameState = GameState::titleMenu;


    sf::Time time;
    
	//create window
	sf::RenderWindow window(sf::VideoMode(800,600),"steelManager",sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);		//set frame limit to 60 fps
    
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
					


					if (button.getButtonBounds().contains(mousePosF)) {
						button.setHoovered(true);
					}
					else
					{
						button.setHoovered(false);
					}

					if (button2.getButtonBounds().contains(mousePosF)) {
						button2.setHoovered(true);
					}
					else
					{
						button2.setHoovered(false);
					}

					break;

				case sf::Event::MouseButtonPressed:
					if(button.getIsHoovered())
						button.setPressed(true);

					if (button2.getIsHoovered())
						button2.setPressed(true);
					break;
				
				case sf::Event::MouseButtonReleased:
					button.setPressed(false);
					button2.setPressed(false);
					break;
            }
        }
        
        time = dT.getElapsedTime();
        long timeElapsed = time.asMilliseconds();
        
     
        
        //update game logic
        dT.restart();		//restart clock 
		button.update(timeElapsed);

        window.clear();		//clear screen
       
        //draw objects
		
		switch (gameState)
		{

		case GameState::titleMenu:

			button.render(window);
			button2.render(window);
		
			break;
		
		default:
			break;
		}


       
        window.display();
    }
    
    return EXIT_SUCCESS ;
}