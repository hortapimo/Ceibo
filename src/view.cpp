#include "view.hpp"

View::View(sf::RenderWindow& window) : window(window){}

void View::render() {
    
    window.clear();
    
    window.display();

    
}

void View::init(){
    window.setSize(sf::Vector2u(800, 600));
    window.setTitle("Ceibo!");
}