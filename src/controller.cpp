#include "controller.hpp"

Controller::Controller(Model& model, View& view) : model(model), view(view) {}

void Controller::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
                // Imprime las coordenadas guardadas
        std::cout << "Mouse position: x = " << savedXPos << ", y = " << savedYPos << std::endl;
    }
}

void Controller::cursor_pos_callback(GLFWwindow* window, double xpos, double ypos) {
    // Guarda las coordenadas del mouse
    
    savedXPos =xpos;
    savedYPos = ypos;
}

void Controller::run() {
//inicializacion de glfw y de la ventana
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
    
//registro de funciones
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorPosCallback(window, cursor_pos_callback);

//loop principal
    while (!glfwWindowShouldClose(window)) {



        view.render(model.getVertices());
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
}