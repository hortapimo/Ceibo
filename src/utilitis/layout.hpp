#pragma once

#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "../Node.hpp"

using vec_prtNodos = std::vector<std::unique_ptr<Node>>;
namespace layout{

    void initialize_positions(vec_prtNodos& ptrNodes,  unsigned int widthScreen, unsigned int heighScreen);

    void apply_repulsion(vec_prtNodos& ptrNodes, double k);

    void apply_attraction(vec_prtNodos& ptrNodes, double k) ;

    void update_positions(vec_prtNodos& ptrNodes, double timestep);
    void spring_layout(vec_prtNodos& ptrNodes, int iterations, double k,
                            double timestep,unsigned int widhtScreen,unsigned int heigthScreen);

}