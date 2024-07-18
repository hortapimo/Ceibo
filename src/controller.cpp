#include "controller.hpp"
#include <GLFW/glfw3.h>

Controller::Controller(Model& model, View& view) : model(model), view(view) {}



void Controller::run() {

     if (!glfwInit()) {
        return;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "MVC Triangle", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);

     while (!glfwWindowShouldClose(window)) {
        view.render(model.getVertices());
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}