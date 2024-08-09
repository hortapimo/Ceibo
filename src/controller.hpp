#ifndef CONTROLLER_H
#define CONTROLLER_H


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

#include "model.hpp"
#include "view.hpp"


class Controller {
public:
    Controller(Model& model, View& view, sf::Event& event);
    
    void init();
    void processEvent();
    void run();
    void test();
    
    static inline float savedXPos = 0.0;
    static inline float savedYPos = 0.0;

private:
    Model& model;
    View& view;
    sf::Event& event;
};


#endif // CONTROLLER_H