#ifndef VIEW_H
#define VIEW_H

#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <memory>
#include <vector>

#include "Graph.hpp"


class ViewManager {
public:
    sf::RenderWindow& window;
    ViewManager(sf::RenderWindow& window);

    void renderQueue();
    int init();
    void loadGraph(Graph & graph);
    void updateMousePosition();
    void movePortV(float offsetX, float offsetY);
    void zoomPortV(float factor);
    
private:

    sf::View camara;
    sf::Font font;
    int loadNodeFigure(std::string nodeName,float x, float y);
    void giveLayout(Graph & graph);
    void createMouseText();
    void _loadNodeEdgesFigures(const std::unique_ptr<Node> & node, const vec_prtNodos & vecPtrNodes);
    void _loadEdge(sf::Vector2f start, sf::Vector2f end, float thickness);
    std::vector<std::unique_ptr<sf::Drawable>> figueresVectorQueue;
    std::vector<std::unique_ptr<sf::RectangleShape>> edgesVectorQueue;
    std::map<std::string ,std::unique_ptr<sf::Text>> textMapQueue;
    
};

#endif // VIEW_H
