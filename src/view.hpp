#ifndef VIEW_H
#define VIEW_H

#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <memory>
#include <vector>

#include "Graph.hpp"

class View {
public:
    sf::RenderWindow& window;
    
    View(sf::RenderWindow& window);
    void render();
    void init();
    void crearCirculo(float radio);
    int loadNodeFigure(std::string nodeName,float x, float y);
    void loadGraph(Graph & graph);
    
 

private:
    std::vector<std::unique_ptr<sf::Drawable>> m_ptrFigueresQueue;
    
};

#endif // VIEW_H
