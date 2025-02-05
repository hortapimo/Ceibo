#include "ViewManager.hpp"
#include <array>
#include <sstream>

#include "layout.hpp"

ViewManager::ViewManager(sf::RenderWindow& window) : window(window){
    
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "no funco la carga de la font\n";
    }

    this->camara = window.getDefaultView();
    this->camara.setSize(sf::Vector2f(window.getSize().x,window.getSize().y));

}

void ViewManager::movePortV(float offsetX, float offsetY){
    camara.move(offsetX, offsetY); 
    window.setView(camara);
}

void ViewManager::zoomPortV(float factor){
    camara.zoom(factor); 
    window.setView(camara);
}

void ViewManager::renderQueue() {
    
    if (!figueresVectorQueue.empty() || !textMapQueue.empty()){
        
        window.setView(camara);
        window.clear(sf::Color(23, 30, 33));

        for (const auto& ptrEdge : edgesVectorQueue)
        {
            window.draw(*ptrEdge);
        }
        for (const auto& ptrFigure : figueresVectorQueue)
        {
            window.draw(*ptrFigure);
        }
        for (const auto& ptrText : textMapQueue)
        {
            window.draw(*ptrText.second);
        }
    
 
        window.display();
    }

    
}

int ViewManager::init(){
    window.setTitle("Ceibo!");
    createMouseText();

    return 1;
}
void ViewManager::createMouseText(){
    std::unique_ptr<sf::Text> mouseText(new sf::Text("nodeName", this->font, 24));
    mouseText->setFillColor(sf::Color::White);
    mouseText->setPosition(10,10);

    textMapQueue.emplace("mouseText", std::move(mouseText));
   
}

void ViewManager::updateMousePosition(){
    
    std::unique_ptr<sf::Text>& mouse = textMapQueue["mouseText"];
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    std::ostringstream oss; 
    oss << "Mouse Position: (" << mousePos.x << ", " << mousePos.y << ")";
    mouse->setString(oss.str());
    
}

int ViewManager::loadNodeFigure(std::string nodeName,float x, float y){
    
    float radio = 10;

    std::unique_ptr<sf::CircleShape> ptrCircle(new sf::CircleShape(radio));

    std::unique_ptr<sf::Text> prtText(new sf::Text(nodeName, this->font, 24));
    prtText->setFillColor(sf::Color::White);
    
    sf::Vector2u size = window.getSize();

    ptrCircle->setFillColor(sf::Color(102, 102, 255));
    ptrCircle->setOrigin(ptrCircle->getLocalBounds().width / 2, ptrCircle->getLocalBounds().height / 2);
    ptrCircle->setPosition(x, y);
    prtText->setOrigin(ptrCircle->getLocalBounds().width / 2, ptrCircle->getLocalBounds().height / 2);
    prtText->setPosition(x, y);
    

    figueresVectorQueue.push_back(std::move(ptrCircle));
    figueresVectorQueue.push_back(std::move(prtText));
    
    return 1;
}

void ViewManager::giveLayout(Graph & graph){
    
    sf::Vector2u screenSize = window.getSize();

    int iterations = 1000;
    double k = 100;
    double timestep = 0.005;

    layout::spring_layout(graph.m_ptrNodes, iterations,k,timestep, screenSize.x, screenSize.y);
    
}

void ViewManager::loadGraph(Graph & graph){

    giveLayout(graph);

    for (size_t i = 0; i < graph.m_ptrNodes.size(); i++){

        loadNodeFigure(graph.m_ptrNodes[i]->getName(),graph.m_ptrNodes[i]->position[0], graph.m_ptrNodes[i]->position[1]);

    }

    for (size_t i = 0; i < graph.m_ptrNodes.size(); i++){

        _loadNodeEdgesFigures(graph.m_ptrNodes[i], graph.m_ptrNodes);

    }
    
}

void ViewManager::_loadNodeEdgesFigures(const std::unique_ptr<Node> & node, const vec_prtNodos & vecPtrNodes){
    sf::Vector2f start = sf::Vector2f(node->position[0],node->position[1]);
    float thickness = 5;

    for(const auto & edge : node->edges){
        float x = vecPtrNodes[edge.parID[1]]->position[0];
        float y = vecPtrNodes[edge.parID[1]]->position[1];
        sf::Vector2f end = sf::Vector2f(x,y);

        _loadEdge(start, end, thickness);
    }
}

void ViewManager::_loadEdge(sf::Vector2f start, sf::Vector2f end, float thickness){

    sf::Vector2f direction = end - start;
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    std::unique_ptr<sf::RectangleShape> ptrEdge(new sf::RectangleShape(sf::Vector2f(length, thickness)));

    ptrEdge->setPosition(start);
    ptrEdge->setRotation(std::atan2(direction.y, direction.x) * 180 / 3.14159f);

    this->edgesVectorQueue.push_back(std::move(ptrEdge));

}