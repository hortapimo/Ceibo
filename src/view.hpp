#ifndef VIEW_H
#define VIEW_H

#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <memory>
#include <vector>

class View {
public:
    sf::RenderWindow& window;
    
    View(sf::RenderWindow& window);
    void render();
    void init();
    void crearCirculo(float radio);
    int drawNode(float x, float y);
    
 

private:
    std::vector<sf::Drawable*> figueresQueue;
    
};

#endif // VIEW_H
