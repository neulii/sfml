#include <SFML/Graphics.hpp>

#include <iostream>


void render(sf::RenderWindow &window);
void update(sf::Time dT);



int main(int argc, const char * argv[]) {
    
    sf::RenderWindow window(sf::VideoMode(800,600),"steelManager");
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
        
        sf::Time time = dT.getElapsedTime();
       
        
        //update game logic
        update(time);
        dT.restart();
        
        
        
        
        //clear screen
        window.clear();
        //draw objects
        render(window);
     
        
        window.display();
    }
    return EXIT_SUCCESS;
}


void render(sf::RenderWindow &window){
    
    
}

void update(sf::Time dT){
    
    
}
