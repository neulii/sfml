#include <SFML/Graphics.hpp>

#include <iostream>
#include "Functions.hpp"

//loading texture zur sprite
sf::Sprite getSpriteFromFile(std::string fileName, std::vector<sf::Texture> &textures){
    
    sf::Texture texture;
    textures.push_back(texture);
    
    if(!texture.loadFromFile(fileName)){
        std::cout << "Failed to load picture: " << fileName << std::endl;
    }
    
    sf::Sprite sprite;
    
    sprite.setTexture(texture);
    return sprite;
    
}


int game() {
    
    std::vector<sf::Texture> textures;
    
    
    
    sf::Texture grassTexture;
    
    bool moveRight = true;
    sf::Time time;
    
    const float SPEED = 0.5;
    
    sf::RenderWindow window(sf::VideoMode(800,600),"steelManager",sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    
    
    sf::Clock dT;
    
    sf::CircleShape circle(20);
    
    sf::Sprite grassSprite = getSpriteFromFile("images/grassField.png",textures);
    grassSprite.setPosition(100, 100);
    
    std::cout << grassSprite.getPosition().x << "    " << grassSprite.getPosition().y << std::endl;
    
    circle.setPosition(10, 10);
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
        
       
        
        if(grassSprite.getPosition().x+grassSprite.getLocalBounds().width>window.sf::Window::getSize().x){
            moveRight = false;
            
        }
        if(grassSprite.getPosition().x<0)
            moveRight = true;
        
        
        if(moveRight)
            grassSprite.move(SPEED * timeElapsed, 0);
           // grassSprite.move(SPEED * time, 0);
        else
            grassSprite.move(-SPEED * timeElapsed, 0);
        
        //draw objects
        window.draw(grassSprite);
        
        window.draw(circle);
        
      
        
        window.display();
    }
    
    return EXIT_SUCCESS ;
}



