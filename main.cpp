#include <SFML/Graphics.hpp>

#include <iostream>

int main(int argc, const char * argv[]) {
   
    
    
    
    sf::RenderWindow window(sf::VideoMode(800,600),"steelManager");
    sf::Clock dT;
    
    sf::CircleShape circle(20);
    
    sf::Texture grassTex;
    
    if(!grassTex.loadFromFile("images/grassField.png")){
        std::cout << "Fehler beim Laden des Bildes";
    }
    
    sf::Sprite grassSprite;
    grassSprite.setTexture(grassTex);
    grassSprite.setPosition(100,100);
    
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
        
        sf::Time time = dT.getElapsedTime();
        //std::cout << time.asMicroseconds() << std::endl;
        
        //update game logic
      
        dT.restart();
        
        //clear screen
        window.clear();
        
        grassSprite.move(0.1,0 );
        //draw objects
        window.draw(grassSprite);
        
        window.draw(circle);
        
      
        
        window.display();
    }
    return EXIT_SUCCESS;
}
