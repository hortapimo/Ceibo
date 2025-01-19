#include "Controller.hpp"
#include <iostream>
#include <mutex>

#include "Node.hpp"
#include "Graph.hpp"

using vec_prtNodos = std::vector<std::unique_ptr<Node>>;

Controller::Controller(Model& model, ViewManager& viewManager) : model(model), viewManager(viewManager) {}

void Controller::init(){
    viewManager.init();
}


void Controller::manageCamaraMovement(const sf::Event& event){

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            this->isDragging = true;
            this->dragStart = viewManager.window.mapPixelToCoords(sf::Mouse::getPosition(viewManager.window));
        } else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
            this->isDragging = false;
        } else if (event.type == sf::Event::MouseMoved && isDragging){
            sf::Vector2f dragEnd = viewManager.window.mapPixelToCoords(sf::Mouse::getPosition(viewManager.window));
            sf::Vector2f offset = dragStart - dragEnd;
            viewManager.movePortV(offset.x, offset.y);
            this->dragStart = viewManager.window.mapPixelToCoords(sf::Mouse::getPosition(viewManager.window)); // update dragStart for continuous dragging
        } else if (event.type == sf::Event::MouseWheelScrolled) {
            if (event.mouseWheelScroll.delta > 0)
            { 
            viewManager.zoomPortV(0.9f); // zoom in 
            } else {
            viewManager.zoomPortV(1.1f);
            // zoom out 
            }
        }


}

void Controller::processEvent(const sf::Event& event){
    
    if(event.type == sf::Event::MouseMoved){
        this->renderMousePosition();
    }

    this->manageCamaraMovement(event);
    
    viewManager.renderQueue();
}

void Controller::renderMousePosition(){
    
    viewManager.updateMousePosition();
}

void Controller::test(){

    if(!functionExecuted){
        
        std::string pathFolder = "C:\\Users\\Hortapimo\\Desktop\\test";
        //std::string pathFolder = "E:\\docs\\OneDrive\\balseiro";
        Graph aux = model.getGraph(pathFolder);
        viewManager.loadGraph(aux);

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