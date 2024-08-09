#include "view.hpp"


View::View(sf::RenderWindow& window) : window(window){}

void View::render() {
    
    window.clear();
    
    for (const auto& ptrFigures : figueresQueue)
        {
            window.draw(*ptrFigures);
        }
    
    window.display();
    
}

//tengo que tener cuidado de liberar la memoria una vez que no necesite lo de la queue
void View::crearCirculo(float radio) {
    sf::CircleShape* ptrCircle = new sf::CircleShape(radio);

    (*ptrCircle).setFillColor(sf::Color::Green);


    figueresQueue.push_back(ptrCircle);
}


void View::init(){
    window.setSize(sf::Vector2u(800, 600));
    window.setTitle("Ceibo!");


}