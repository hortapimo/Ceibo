#include "model.hpp"
#include "view.hpp"
#include "controller.hpp"



int main() {

    sf::RenderWindow window(sf::VideoMode(200, 200), "Ceibo");
    sf::Event event;

    Model model;
    View view(window);
    Controller controller(model, view, event);

    controller.init();

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
