#include "Model.hpp"
#include "ViewManager.hpp"
#include "Controller.hpp"


int main() {

    //window and event creation
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1600, 900), "Anti-Aliasing Example", sf::Style::Default, settings);
    window.setFramerateLimit(60);
    sf::Event event;

//Model-View-Controler architecture
    Model model;
    ViewManager viewManager(window);
    Controller controller(model, viewManager);

//init things
    controller.init();

//Main loop
    while (window.isOpen())
    {
        
        //colect events, and close the windows if event is close
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            controller.test();
            controller.processEvent(event);
        }
        
    }

    return 0;
}
