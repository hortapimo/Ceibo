#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <iostream>
#include <filesystem>

#include "Node.hpp"
#include "Graph.hpp"

int Node::nextId = 1;

class Model {

private:
    

public:
    Model();
    
    std::vector<std::string> Model::listFolderAndFilesOfFolder(const std::string& directory_path);
    std::vector<Node> getNodesOfFolder(std::string filePath,  Node fatherNode);
    std::vector<Node> getNodesOfRootFolder(std::filesystem::path filePath);


    std::vector<int> Model::getRowForAdjacencyMatrix(std::vector<std::string> listFoldersAndFiles); // no imp

   
    void Model::printNodes(std::vector<Node> & nodos);
    Graph getGraph(const std::string directory_path); 

    
};

#endif // MODEL_H
