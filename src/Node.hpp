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

public:
    std::string name;
    std::vector<Edge> edges;
    float position[2] = {0,0};   

    Node();
    Node(std::string name);
    void addEdge(Node node1, Node node2);
    
    int getID();
    std::string getName();

};

#endif

