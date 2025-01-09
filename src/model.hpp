#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <iostream>
#include <filesystem>
#include <unordered_map>

#include "Node.hpp"
#include "Graph.hpp"

using vec_prtNodos = std::vector<std::unique_ptr<Node>>;
using Matrix = std::vector<std::vector<int>>;
using map_IdRows = std::unordered_map<size_t,size_t>;

class Model {

private:
    

public:
    Model();
    
    std::vector<std::string> listFolderAndFilesOfFolder(const std::string& directory_path);
    vec_prtNodos getNodesOfFolder(std::string filePath,  Node& fatherNode);
    vec_prtNodos Model::getNodesOfRootFolder(std::filesystem::path filePath, Node & rootNode);

    Matrix buildAdyacencyMatrix(const vec_prtNodos & prtNodos);
    map_IdRows getMapIdRows(const vec_prtNodos & ptrsNodes);
    std::vector<int> getRowForAdyacencyMatrix(Node Node, size_t nCols); // no imp

   
    void printNodes(vec_prtNodos & nodos);

    
    Graph getGraph(const std::string directory_path); 
};

#endif // MODEL_H
