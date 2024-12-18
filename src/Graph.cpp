#include <vector>

#include "Graph.hpp"

Graph::Graph()
{
}

void Graph::add_nodes(std::vector<Node> newNodes){
    for (const Node node: newNodes){
        m_nodes.push_back(node);
    } 
}
