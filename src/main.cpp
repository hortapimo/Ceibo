#include <iostream>
#include <glfw3.h>

int main() {
    std::cout << "hola pa\n";

     if (!glfwInit()) {
        std::cout << "Error al inicializar GLFW" << std::endl;
        return -1;
    }

    // Configura la ventana GLFW aquí
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "Mi Ventana GLFW", NULL, NULL);

    while (!glfwWindowShouldClose(window)) {
    // Lógica de la aplicación
    // ...

    glfwSwapBuffers(window); // Intercambia los buffers de la ventana
    glfwPollEvents(); // Maneja eventos
}

    glfwTerminate();
    return 0;
}
