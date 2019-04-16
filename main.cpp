#include <SFML/Graphics.hpp>

#include <iostream>

int main(int argc, const char * argv[]) {
    sf::RenderWindow window(sf::VideoMode(800,600),"steelManager");
    
    while (window.isOpen()) {
        sf::Event event;
        sf::Clock clock;
        
        while(window.pollEvent(event)){
            switch (event.type){
                case sf::Event::Closed:
                    window.close();
                    
                    break;

            }
        }
 
        clock.restart();
        //update game logic
        
        window.clear();
        //draw objects
        
        sf::CircleShape shape(10);
        shape.setPosition(100,100);
        shape.setFillColor(sf::Color::Red);
        
        window.draw(shape);
        
        window.display();
    }
    return EXIT_SUCCESS;
}
