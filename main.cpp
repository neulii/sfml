#include <SFML/Graphics.hpp>

#include <iostream>
#include "Functions.hpp"
#include "Tile.h"
#include "FieldType.h"

int game() {
	sf::Texture coalField;
	sf::Image testImage;
   

	
    sf::Time time;
    
	//create window
	sf::RenderWindow window(sf::VideoMode(800,600),"steelManager",sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    

	if (!coalField.loadFromFile("images/coalField.png")) {
		std::cout << "Fehler beim Laden des bildes" << std::endl;

	}

	if (!testImage.loadFromFile("images/coalfield.png")) {
		std::cout << "Fehler beim Laden des bildes" << std::endl;

	}

	Tile tile(FieldType::coalField, 100, 100, coalField);

	const int BRIGHTNESS = -50;

	sf::Color tempPixel;

	for (int i = 0; i < testImage.getSize().x;i++) {
		for (int j = 0; j < testImage.getSize().y; j++) {
			tempPixel = testImage.getPixel(i, j);
			tempPixel = tempPixel + sf::Color(BRIGHTNESS,BRIGHTNESS, BRIGHTNESS);
			testImage.setPixel(i,j,tempPixel);

		}

	}

    sf::Clock dT;


	sf::Texture test;


	test.loadFromImage(testImage);


	sf::Sprite testSprite;
	testSprite.setTexture(test);
	testSprite.setPosition(160, 100);

    
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

		window.draw(testSprite);
		
        window.display();
    }
    
    return EXIT_SUCCESS ;
}



