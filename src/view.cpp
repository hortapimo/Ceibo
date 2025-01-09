#include "View.hpp"
#include <array>

View::View(sf::RenderWindow& window) : window(window){}

void View::render() {
    
    if (!m_ptrFigueresQueue.empty()){

        for (const auto& ptrFigure : m_ptrFigueresQueue)
        {
            window.draw(*ptrFigure);
        }

        m_ptrFigueresQueue.clear();
        window.display();
    }

    
}

//tengo que tener cuidado de liberar la memoria una vez que no necesite lo de la queue
void View::crearCirculo(float radio) {
    
    std::unique_ptr<sf::CircleShape> ptrCircle(new sf::CircleShape(radio));

    (*ptrCircle).setFillColor(sf::Color::Green);


    m_ptrFigueresQueue.push_back(std::move(ptrCircle));
}


void View::init(){
    window.setSize(sf::Vector2u(800, 600));
    window.setTitle("Ceibo!");


}

int View::loadNodeFigure(std::string nodeName,float x, float y){
    
    float radio = 5;

    std::unique_ptr<sf::CircleShape> ptrCircle(new sf::CircleShape(radio));
    
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "no funco la carga de la font\n";
        return -1; // Error handling
    }

    std::unique_ptr<sf::Text> prtText(new sf::Text("nodeName", font, 24));
    prtText->setFillColor(sf::Color::White);
    
    sf::Vector2u size = window.getSize();

    ptrCircle->setFillColor(sf::Color::Red);
    ptrCircle->setOrigin(ptrCircle->getLocalBounds().width / 2, ptrCircle->getLocalBounds().height / 2);
    ptrCircle->setPosition(x, y);
    prtText->setOrigin(ptrCircle->getLocalBounds().width / 2, ptrCircle->getLocalBounds().height / 2);
    prtText->setPosition(x, y);
    

    m_ptrFigueresQueue.push_back(std::move(ptrCircle));
    //m_ptrFigueresQueue.push_back(std::move(prtText));
    
    return 1;
}

void View::loadGraph(Graph & graph){
    float x = 10;
    float y = 10;
    for (size_t i = 0; i < graph.m_ptrNodes.size(); i++){

        loadNodeFigure(graph.m_ptrNodes[i]->getName(),graph.m_ptrNodes[i]->position[0], graph.m_ptrNodes[i]->position[1]);

    }
}