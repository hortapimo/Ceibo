#ifndef NODES_H
#define NODES_H

#include <iostream>
#include <vector>

#include "Edge.hpp"

class Node
{
private:
    
    static int nextId;
    int id;
    std::vector<Edge> edges;   

public:
    std::string name;

    Node(std::string name);
    void addEdge(Node node1, Node node2);
    
    int getID();

};

#endif

