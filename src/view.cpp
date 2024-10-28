#include "View.hpp"
#include <array>

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

int View::drawNode(float x, float y){
    
    float radio = 100;

    sf::CircleShape* ptrCircle = new sf::CircleShape(radio);

    sf::Font* prtFont = new sf::Font;
    if (!(*prtFont).loadFromFile("arial.ttf")) {
        std::cout << "no funco la carga de la font\n";
        return -1; // Error handling
    }

    sf::Text* prtText = new sf::Text("Hello", *prtFont, 24);

   (*prtText).setFillColor(sf::Color::White);
    
    sf::Vector2u size = window.getSize();

    (*ptrCircle).setFillColor(sf::Color::Red);
    (*ptrCircle).setOrigin(0.5,0.5);
    (*ptrCircle).setPosition(50, 10);
    std::cout << x<< std::endl;
    (*prtText).setOrigin(0.5,0.5);
    (*prtText).setPosition(x/4, y/4);
    

    figueresQueue.push_back(ptrCircle);
    figueresQueue.push_back(prtText);
    
    return 1;
}