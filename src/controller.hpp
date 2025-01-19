#ifndef CONTROLLER_H
#define CONTROLLER_H


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

#include "model.hpp"
#include "ViewManager.hpp"


class Controller {
public:
    Controller(Model& model, ViewManager& viewManager);
    
    void init();
    void processEvent(const sf::Event& event);
    void run();
    void test();
    void renderMousePosition();
    void manageCamaraMovement(const sf::Event& event);
    
    static inline float savedXPos = 0.0;
    static inline float savedYPos = 0.0;

private:
    Model& model;
    ViewManager& viewManager;
    //sf::Event& _event;
    bool isDragging;
    sf::Vector2f dragStart;
    bool functionExecuted = false;
};


#endif // CONTROLLER_H