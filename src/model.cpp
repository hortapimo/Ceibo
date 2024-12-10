#include "Model.hpp"
#include <fstream>
#include "Node.hpp"

using vec_Nodos = std::vector<Node>;

Model::Model() {


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

}

vec_Nodos Model::getNodesOfFolder(std::string filePath, Node fatherNode){
    
    std::vector<std::string> stringNodesList = listFolderAndFilesOfFolder(filePath);
    vec_Nodos nodos(stringNodesList.size());

    int i = 0;
    for (std::string fileFolderName : stringNodesList){
        
        Node nodo(fileFolderName);
        nodo.addEdge(nodo,fatherNode);
        nodos[i]=nodo;
        i++;
    }

    return nodos;
}

vec_Nodos Model::getNodesOfRootFolder(std::filesystem::path filePath){
    Node rootNode(filePath.filename().string());
    vec_Nodos nodos  = getNodesOfFolder(filePath.string(), rootNode);


    if (std::filesystem::exists(filePath) && std::filesystem::is_directory(filePath)) {

        for (const auto& entry : std::filesystem::directory_iterator(filePath)) {

           if(entry.is_directory()){
            concatenateVector(nodos, getNodesOfRootFolder(entry.path().string()));
           }

        }

    } else {
        std::cout << "Directory does not exist!" << std::endl;
    }

    return nodos;
}



void Model::printNodes(vec_Nodos & nodos){
    for(Node nodo: nodos){
        std::cout << nodo.name << std::endl;
    }
}

Graph Model::getGraph(const std::string directory_path){
    Graph graph;


    //graph.add_nodes(getNodesOfFolder(directory_path, ));
    

    return graph;
}

static void concatenateVector(vec_Nodos & vec1, const vec_Nodos & vec2 ){
    vec1.insert(vec1.begin(),vec2.begin(), vec2.end());
}
