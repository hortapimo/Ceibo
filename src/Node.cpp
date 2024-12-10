#include "Node.hpp"

Node::Node(std::string name_) : id(nextId)
{
nextId++;
name = name_;
}

void Node::addEdge(Node node1, Node node2){
    Edge edge(node1, node2);
    edges.push_back(edge);
}

int Node::getID(){
    return id
}

