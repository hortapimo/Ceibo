#ifndef VIEW_H
#define VIEW_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <memory>
#include <vector>

class View {
public:
    View(sf::RenderWindow& window);
    void render();
    void init();
    void crearCirculo(float radio);
    
 

private:
    sf::RenderWindow& window;
    std::vector<sf::Drawable*> figueresQueue;
    
};

#endif // VIEW_H
