#include "Model.hpp"
#include <fstream>
#include "Node.hpp"


using vec_prtNodos = std::vector<std::unique_ptr<Node>>;
using Matrix = std::vector<std::vector<int>>;


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

// std::vector<int> Model::getRowForAdjacencyMatrix(std::vector<std::string> listFoldersAndFiles){

// }

vec_prtNodos Model::getNodesOfFolder(std::string filePath, Node fatherNode){
    
    std::vector<std::string> stringNodesList = listFolderAndFilesOfFolder(filePath);
    vec_prtNodos nodos;
    nodos.reserve(stringNodesList.size());


    for (std::string fileFolderName : stringNodesList){
        
        std::unique_ptr<Node> prtNode = std::make_unique<Node>(fileFolderName);
        prtNode->addEdge(*prtNode,fatherNode);
        nodos.push_back(std::move(prtNode));
    }

    return nodos;
}

vec_prtNodos Model::getNodesOfRootFolder(std::filesystem::path filePath){
    Node rootNode(filePath.filename().string());
    vec_prtNodos nodos  = getNodesOfFolder(filePath.string(), rootNode);


    if (std::filesystem::exists(filePath) && std::filesystem::is_directory(filePath)) {

        for (const auto& entry : std::filesystem::directory_iterator(filePath)) {

           if(entry.is_directory()){
            vec_prtNodos aux = getNodesOfRootFolder(entry.path());
            nodos.insert(nodos.end(), std::make_move_iterator(aux.begin()), std::make_move_iterator(aux.end())); //concateno el vector de nodos "padre" con los demas nodos "hijos"
           }

        }

    } else {
        std::cout << "Directory does not exist!" << std::endl;
    }

    return nodos;
}

void Model::printNodes(vec_prtNodos & nodos){
    for(auto & ptrNodo: nodos){
        std::cout << "nodo:" << ptrNodo->name << " - id:" << ptrNodo->getID() << std::endl;
    }
}

std::vector<int> Model::getRowForAdyacencyMatrix(Node Node, size_t nCols, map_IdRows mapIdRows)
{

    std::vector<int> row(nCols);

    for (Edge edg : Node.edges){
        std::cout <<  mapIdRows[edg.parID[1]] <<"\n";
        size_t oneInColumn = mapIdRows[edg.parID[1]];
        row[oneInColumn]=1;
    }

    return row;
}

map_IdRows Model::getMapIdRows(const vec_prtNodos & ptrsNodes){
    map_IdRows mapIdNodes;

    for (size_t i=0; i< ptrsNodes.size(); i++){
        //agregar un atributo de fila en los nodos?
        size_t id = ptrsNodes[i]->getID();
        mapIdNodes[id] = i;
    }

    return mapIdNodes;
}

Matrix Model::buildAdyacencyMatrix(const vec_prtNodos & ptrsNodes){

    size_t nColumns = ptrsNodes.size();
    map_IdRows mapIdNodes = getMapIdRows(ptrsNodes);

    Matrix adyacencyMatrix; 
    for (const auto& ptrNode: ptrsNodes){ 
        adyacencyMatrix.emplace_back(getRowForAdyacencyMatrix(*ptrNode , nColumns, map_IdRows));
    }

    return adyacencyMatrix;
}

Graph Model::getGraph(const std::string directory_path){
    Graph graph;
    
    vec_prtNodos nodes = getNodesOfRootFolder(directory_path);
    Matrix adyancecyMatrix = buildAdyacencyMatrix(nodes);
    //graph.add_nodes(getNodesOfFolder(directory_path));
    //graph.addAdyancecyMatrix(adyancecyMatrix)

    return graph;
}
