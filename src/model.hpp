#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <iostream>
#include <filesystem>

#include "Node.hpp"
#include "Graph.hpp"

class Model {

private:
    

public:
    Model();
    
    std::vector<std::string> listFolderAndFiles(const std::string& directory_path);
    std::vector<std::string> Model::listFolderAndFilesOfFolder(const std::string& directory_path);


    std::vector<int> Model::getRowForAdjacencyMatrix(std::vector<std::string> listFoldersAndFiles);

    std::vector<Node> getNodesOfFolder(std::string filePath);
    void Model::printNodes(std::vector<Node> & nodos);
    Graph getGraph(const std::string directory_path); 

    
};

#endif // MODEL_H
