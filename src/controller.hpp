#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.hpp"
#include "view.hpp"

class Controller {
public:
    Controller(Model& model, View& view);
    void run();

private:
    Model& model;
    View& view;
};

#endif // CONTROLLER_H