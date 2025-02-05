#include <vector>

#include "Graph.hpp"


Graph::Graph()
{
}

void Graph::add_nodes(vec_prtNodos & nodes){
    for (size_t i =0; i<nodes.size();i++){
        m_ptrNodes.push_back(std::move(nodes[i]));
    } 

}
void Graph::add_adjacencyMatrix(Matrix matrix){
    m_adjacencyMatrix = matrix;
}