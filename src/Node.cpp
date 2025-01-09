#include "Node.hpp"

int Node::nextId = 0;

Node::Node() : id(nextId)
{
nextId++;
}

Node::Node(std::string name_) : id(nextId)
{
nextId++;
name = name_;
}

void Node::addEdge(Node node1, Node node2){
    Edge edge(node1.getID(), node2.getID());
    edges.push_back(edge);
}


int Node::getID(){
    return id;
}

std::string Node::getName(){
    return name;
}
