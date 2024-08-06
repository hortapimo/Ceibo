#include "model.hpp"
#include "view.hpp"
#include "controller.hpp"


int main() {
    Model model;
    View view;
    Controller controller(model, view);

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");


    while (window.isOpen())
    {

        controller.tomarEvento();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }



*/

    controller.run();



    return 0;
}
