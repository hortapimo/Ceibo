#pragma once

#include <vector>
#include <iostream>
#include <filesystem>
#include <unordered_map>

#include "Node.hpp"
#include "Graph.hpp"

using vec_prtNodos = std::vector<std::unique_ptr<Node>>;
using Matrix = std::vector<std::vector<int>>;
using map_IdRows = std::unordered_map<size_t,size_t>;

namespace graphConstructor {

    Graph getGraph(const std::string directory_path);

};


