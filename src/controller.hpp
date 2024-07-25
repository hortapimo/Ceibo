#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "model.hpp"
#include "view.hpp"


class Controller {
public:
    Controller(Model& model, View& view);
    static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    static void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);
    void run();
    static inline float savedXPos = 0.0;
    static inline float savedYPos = 0.0;

private:
    Model& model;
    View& view;
};


#endif // CONTROLLER_H