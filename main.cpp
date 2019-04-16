#include <SFML/Graphics.hpp>

#include <iostream>

int main(int argc, const char * argv[]) {
    sf::RenderWindow window(sf::VideoMode(800,600),"super fenster");
    
    while (window.isOpen()) {
        sf::Event event;
        sf::Clock clock;
        
        while(window.pollEvent(event)){
            switch (event.type){
                case sf::Event::Closed:
                    window.close();
                    
                    //test
                    break;
        
                    


                case sf::Event::Resized:
                    std::cout << "super resized";
                    
                    break;
                case sf::Event::LostFocus:
                    
                    break;
                case sf::Event::GainedFocus:
                    
                    break;
                case sf::Event::TextEntered:
                    
                    break;
                case sf::Event::KeyPressed:
                    
                    break;
                case sf::Event::KeyReleased:
                    
                    break;
                case sf::Event::MouseWheelMoved:
                    
                    break;
                case sf::Event::MouseWheelScrolled:
                    
                    break;
                case sf::Event::MouseButtonPressed:
                
                    break;
                case sf::Event::MouseButtonReleased:
                    
                    break;
                case sf::Event::MouseMoved:
                    std::cout << sf::Mouse::getPosition(window).x << "  /  " << sf::Mouse::getPosition(window).y << std::endl;
                    break;
                case sf::Event::MouseEntered:
                    
                    break;
                case sf::Event::MouseLeft:
                    
                    break;
               
              
            }
        }
        
        //std::cout << "elapsed time: " << clock.getElapsedTime().asMicroseconds()<< "\n";
        
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
