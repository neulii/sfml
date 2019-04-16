#include <SFML/Graphics.hpp>

#include <iostream>

int main(int argc, const char * argv[]) {
    
    sf::RenderWindow window(sf::VideoMode(800,600),"steelManager");
    sf::Clock dT;
    
    sf::CircleShape circle(20);
    circle.setPosition(100, 100);
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
       
        
        //update game logic
      
        dT.restart();
        
        //clear screen
        window.clear();
        
        //draw objects
        
        window.draw(circle);
        
      
        
        window.display();
    }
    return EXIT_SUCCESS;
}
