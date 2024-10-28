#pragma once

#include "Node.hpp"
#include "Edge.hpp"

using Matrix = std::vector<std::vector<int>>;

class Graph
{
private:
    /* data */
public:
    std::vector<Node> m_nodes;
    std::vector<Edge> m_edges;
    Matrix m_adjacencyMatrix;

    Graph();
    void add_nodes(std::vector<Node> nodes);
};
