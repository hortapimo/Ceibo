#include <vector>

#include "Graph.hpp"

int Node::nextId = 1; //incializo la variale estatica de nodo.

Graph::Graph()
{
}

void Graph::add_nodes(std::vector<Node> newNodes){
    for (const Node node: newNodes){
        m_nodes.push_back(node);
    } 
}
