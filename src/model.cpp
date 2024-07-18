#include "model.hpp"

Model::Model() {
    vertices = {
        0.0f,  0.5f, 0.0f,
       -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };
}

const std::vector<float>& Model::getVertices() const {
    return vertices;
}