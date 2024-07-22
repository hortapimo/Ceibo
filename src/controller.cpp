#include "controller.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

Controller::Controller(Model& model, View& view) : model(model), view(view) {}



void Controller::run() {

     if (!glfwInit()) {
        return;
    }
    GLFWwindow* window = glfwCreateWindow(640, 480, "Ceibo", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);


    if(glewInit() != GLEW_OK){
        std::cout <<"error glew!\n";
    }
    
    while (!glfwWindowShouldClose(window)) {
        view.render(model.getVertices());
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}