#include "Model.hpp"
#include <fstream>
#include "Node.hpp"

Model::Model() {


}



std::vector<std::string> Model::listFolderAndFiles(const std::string& directory_path){

    std::vector<std::string> filesFolderNames;
  
    try {
        for (const auto & entry : std::filesystem::directory_iterator(directory_path)) {
            filesFolderNames.push_back(entry.path().filename().string());
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return filesFolderNames;
}


std::vector<std::string> Model::listFolderAndFilesOfFolder(const std::string& directory_path){

    std::vector<std::string> filesFolderNames;
    std::filesystem::path dirPath{directory_path};

    if (std::filesystem::exists(dirPath) && std::filesystem::is_directory(dirPath)) {
        for (const auto& entry : std::filesystem::directory_iterator(dirPath)) {
            filesFolderNames.push_back(entry.path().filename().string());
        }
    } else {
        std::cout << "Directory does not exist!" << std::endl;
    }

    return filesFolderNames;
}

std::vector<int> Model::getRowForAdjacencyMatrix(std::vector<std::string> listFoldersAndFiles){
std::vector<int> row()
}

std::vector<Node> Model::getNodesOfFolder(std::string filePath){
    std::vector<Node> nodos;
    
    std::vector<std::string> stringNodesList = listFolderAndFiles(filePath);
    
    for (std::string fileFolderName : stringNodesList){
        
        Node nodo(fileFolderName);

        nodos.push_back(nodo);
    }

    return nodos;
}

void Model::printNodes(std::vector<Node> & nodos){
    for(Node nodo: nodos){
        std::cout << nodo.name << std::endl;
    }
}

Graph Model::getGraph(const std::string directory_path){
    Graph graph;


    graph.add_nodes(getNodesOfFolder(directory_path));
    

    return graph;
}