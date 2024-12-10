#pragma once
#include"Node.hpp"

class Edge
{
private:
    int parID[2];

public:
    Edge(Node node1, Node node2);
};
