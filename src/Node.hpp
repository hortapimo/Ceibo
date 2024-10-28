#ifndef NODES_H
#define NODES_H

#include <iostream>

class Node
{
private:
    
    static int nextId;
    int id;

public:
    std::string name;

    Node(std::string name);

};

#endif

