#include "controller.hpp"

Controller::Controller(Model& model, View& view) : model(model), view(view) {}

void Controller::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {

}

void Controller::cursor_pos_callback(GLFWwindow* window, double xpos, double ypos) {
    // Guarda las coordenadas del mouse
    
    savedXPos =xpos;
    savedYPos = ypos;
}

void Controller::run() {

}