#include "controller.hpp"

Controller::Controller(Model& model, View& view, sf::Event& event) : model(model), view(view), event(event) {}

void Controller::init(){
    view.init();
}

void Controller::processEvent(){

    view.render();
}

void Controller::test(){
    view.crearCirculo(10.0f);
    view.render();
}

void Controller::run() {

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

}