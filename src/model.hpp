#ifndef MODEL_H
#define MODEL_H

#include <vector>

class Model {
public:
    Model();
    const std::vector<float>& getVertices() const;

private:
    std::vector<float> vertices;
};

#endif // MODEL_H
