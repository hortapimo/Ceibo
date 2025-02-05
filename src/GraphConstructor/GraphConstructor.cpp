#include "GraphConstructor.hpp"
#include <fstream>
#include "Node.hpp"


using vec_prtNodos = std::vector<std::unique_ptr<Node>>;
using Matrix = std::vector<std::vector<int>>;


std::vector<std::string> listFolderAndFilesOfFolder(const std::string& directory_path);
vec_prtNodos getNodesOfFolder(std::string filePath,  Node& fatherNode);
vec_prtNodos getNodesOfRootFolder(std::filesystem::path filePath, Node & rootNode);
Matrix buildAdyacencyMatrix(const vec_prtNodos & prtNodos);
map_IdRows getMapIdRows(const vec_prtNodos & ptrsNodes);
std::vector<int> getRowForAdyacencyMatrix(Node Node, size_t nCols); // no imp
Graph getGraph(const std::string directory_path); 

std::vector<std::string> listFolderAndFilesOfFolder(const std::string& directory_path){

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

    vec_prtNodos getNodesOfFolder(std::string filePath, Node & fatherNode){
        
        std::vector<std::string> stringNodesList = listFolderAndFilesOfFolder(filePath);
        vec_prtNodos nodos;
        nodos.reserve(stringNodesList.size());

        for (std::string fileFolderName : stringNodesList){
            
            std::unique_ptr<Node> prtNode = std::make_unique<Node>(fileFolderName);
            prtNode->addEdge(*prtNode,fatherNode);
            nodos.emplace_back(std::move(prtNode));
        }

        return nodos;
    }

    size_t findNodeByName(std::string name, const vec_prtNodos & prtNodos)
    {
        
        size_t i = 0;
        for (const auto & node: prtNodos){
            if (node->getName() == name){
                break;
            }
            else{
                i ++;
            }
        }


        return i;
    }

    vec_prtNodos getNodesOfRootFolder(std::filesystem::path filePath, Node & rootNode){
        vec_prtNodos nodos  = getNodesOfFolder(filePath.string(), rootNode);


        if (std::filesystem::exists(filePath) && std::filesystem::is_directory(filePath)) {

            for (const auto& entry : std::filesystem::directory_iterator(filePath)) {

            if(entry.is_directory()){
                std::string nodeName = entry.path().filename().string();
                size_t i = findNodeByName(nodeName, nodos);
                vec_prtNodos aux = getNodesOfRootFolder(entry.path(),*nodos[i]);
                nodos.insert(nodos.end(), std::make_move_iterator(aux.begin()), std::make_move_iterator(aux.end())); //concateno el vector de nodos "padre" con los demas nodos "hijos"
            }

            }

        } else {
            std::cout << "Directory does not exist!" << std::endl;
        }

        return nodos;
    }

    void printNodes(vec_prtNodos & nodos){
        for(auto & ptrNodo: nodos){
            std::cout << "nodo:" << ptrNodo->name << " - id:" << ptrNodo->getID() << std::endl;
        }
    }

    std::vector<int> getRowForAdyacencyMatrix(Node Node, size_t nCols)
    {

        std::vector<int> row(nCols);

        for (Edge edg : Node.edges){
            size_t oneInColumn = edg.parID[1];
            row[oneInColumn]=1;
        }

        return row;
    }

    map_IdRows getMapIdRows(const vec_prtNodos & ptrsNodes){
        map_IdRows mapIdNodes;

        for (size_t i=0; i< ptrsNodes.size(); i++){
            //agregar un atributo de fila en los nodos?
            size_t id = ptrsNodes[i]->getID();
            mapIdNodes[id] = i;
        }

        return mapIdNodes;
    }

    Matrix buildAdyacencyMatrix(const vec_prtNodos & ptrsNodes){

        size_t nColumns = ptrsNodes.size();

        Matrix adyacencyMatrix; 

        for (const auto& ptrNode: ptrsNodes){ 
            adyacencyMatrix.emplace_back(getRowForAdyacencyMatrix(*ptrNode , nColumns));
        }

        return adyacencyMatrix;
    }



namespace graphConstructor{
 
    Graph getGraph(const std::string directory_path){
        Graph graph;

        //I get the node vector
        std::unique_ptr<Node> ptrFatherNode = std::make_unique<Node>("Root");
        vec_prtNodos nodes = getNodesOfRootFolder(directory_path, *ptrFatherNode);
        nodes.insert(nodes.begin(), std::move(ptrFatherNode));

        Matrix adyancecyMatrix = buildAdyacencyMatrix(nodes);
        graph.add_nodes(nodes);
        graph.add_adjacencyMatrix(adyancecyMatrix);

        return graph;
    }
}