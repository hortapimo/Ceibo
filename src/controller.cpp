#include "Controller.hpp"
#include <iostream>
#include <mutex>

#include "Node.hpp"

Controller::Controller(Model& model, View& view, sf::Event& event) : model(model), view(view), event(event) {}

void Controller::init(){
    view.init();
}

void Controller::processEvent(){

    view.render();
}

void Controller::test(){

    static bool functionExecuted = false;
    //view.crearCirculo(10.0f);
    
    view.render();
    if(!functionExecuted){
        std::string pathFolder = "E:\\docs\\OneDrive\\balseiro";
        std::vector<Node> nodos = model.getNodesOfFolder(pathFolder);
        
        view.init();
        model.printNodes(nodos);
        sf::Vector2u size = view.window.getSize();
        view.drawNode(size.x/2, size.y/2);
        functionExecuted = true;
    } 
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