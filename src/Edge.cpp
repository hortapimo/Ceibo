#include "Edge.hpp"

Edge::Edge(Node node1, Node node2){

    parID[0] =node1.getID();
    parID[1] =node2.getID();

}