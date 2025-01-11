
#include "layout.hpp"


void layout::initialize_positions(vec_prtNodos& ptrNodes, unsigned int widthScreen, unsigned int heighScreen) {
        srand(time(0));
        for (auto& ptrNode : ptrNodes) {
            ptrNode->position[0] = static_cast<double>(rand()) / RAND_MAX * static_cast<float>(widthScreen);
            ptrNode->position[1] = static_cast<double>(rand()) / RAND_MAX * static_cast<float>(heighScreen);
        }
    }

void layout::apply_repulsion(vec_prtNodos& prtNodes, double k) {
    for (size_t i = 0; i < prtNodes.size(); ++i) {
        for (size_t j = i + 1; j < prtNodes.size(); ++j) {
            double dx = prtNodes[i]->position[0] - prtNodes[j]->position[0];
            double dy = prtNodes[i]->position[1] - prtNodes[j]->position[1];
            double distance = std::sqrt(dx * dx + dy * dy);
            if (distance < 1e-6){
                distance = 1e-6;
            } else{
            double repulsive_force = k * k / (distance*40);
            prtNodes[i]->dx += repulsive_force * dx / distance;
            prtNodes[i]->dy += repulsive_force * dy / distance;
            prtNodes[j]->dx -= repulsive_force * dx / distance;
            prtNodes[j]->dy -= repulsive_force * dy / distance;
            }
            
        }
    }
}

    void layout::apply_attraction(vec_prtNodos& ptrNodes, double k) {
        for (const auto& ptrNode : ptrNodes) {
            Node& node1 = *ptrNode;
            for(auto edge : node1.edges){
                Node& node2 = *ptrNodes[edge.parID[1]];
                double dx = node1.position[0] - node2.position[0];
                double dy = node1.position[1] - node2.position[1];
                double distance = std::sqrt(dx * dx + dy * dy);
                double attractive_force = (distance * distance) / k;
                if (distance < 1e-6){
                    distance = 1e-6;
                } else{      
                    node1.dx -= attractive_force * dx / distance;
                    node1.dy -= attractive_force * dy / distance;
                    node2.dx += attractive_force * dx / distance;
                    node2.dy += attractive_force * dy / distance;  
            }
            }
             
        }
    }

    void layout::update_positions(vec_prtNodos& ptrNodes, double timestep) {
        for (auto& ptrNode : ptrNodes) {
            ptrNode->position[0] += ptrNode->dx * timestep;
            ptrNode->position[1] += ptrNode->dy * timestep;
            ptrNode->dx = 0;
            ptrNode->dy = 0;
        }
    }

void layout::spring_layout(vec_prtNodos& ptrNodes, int iterations, double k,
                            double timestep, unsigned int heigthScreen, unsigned int widhtScreen) {
    layout::initialize_positions(ptrNodes, widhtScreen, heigthScreen);
    for (int i = 0; i < iterations; ++i) {
        layout::apply_repulsion(ptrNodes, k);
        layout::apply_attraction(ptrNodes, k);
        layout::update_positions(ptrNodes, timestep);
    }
}

    /* Ejemplo
    int main() {
        std::vector<Node> nodes = {{0}, {1}, {2}, {3}};
        std::vector<std::pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};

        int iterations = 100;
        double k = 0.1;
        double timestep = 0.01;

        spring_layout(nodes, edges, iterations, k, timestep);

        for (const auto& node : nodes) {
            std::cout << "Node " << node.id << ": (" << node.x << ", " << node.y << ")\n";
        }

        return 0;
    }*/
