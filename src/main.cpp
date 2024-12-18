#include "Model.hpp"
#include "View.hpp"
#include "Controller.hpp"

int main() {

//window and event creation
    sf::RenderWindow window(sf::VideoMode(200,200), "Ceibo");
    sf::Event event;

//Model-View-Controler architecture
    Model model;
    View view(window);
    Controller controller(model, view, event);

//init things
    controller.init();

//Main loop
    while (window.isOpen())
    {
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //controller.processEvent();
        controller.test();

    }

    return 0;
}
