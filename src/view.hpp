#ifndef VIEW_H
#define VIEW_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <vector>

class View {
public:
    View(sf::RenderWindow& window);
    void render();
    void init();

private:
    sf::RenderWindow& window;
};

#endif // VIEW_H
