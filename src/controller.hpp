#ifndef CONTROLLER_H
#define CONTROLLER_H


#include <SFML/Window.hpp>

#include <iostream>

#include "model.hpp"
#include "view.hpp"


class Controller {
public:
    Controller(Model& model, View& view);
    void run();
    static inline float savedXPos = 0.0;
    static inline float savedYPos = 0.0;

private:
    Model& model;
    View& view;
};


#endif // CONTROLLER_H