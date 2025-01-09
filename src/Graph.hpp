#pragma once

#include "Node.hpp"
#include "Edge.hpp"

using Matrix = std::vector<std::vector<int>>;
using vec_prtNodos = std::vector<std::unique_ptr<Node>>;

class Graph
{
private:
    /* data */
public:
    std::vector<std::unique_ptr<Node>> m_ptrNodes;
    Matrix m_adjacencyMatrix;

    Graph();
    void add_nodes(vec_prtNodos & nodos);
    void add_adjacencyMatrix(Matrix matrix);

};
