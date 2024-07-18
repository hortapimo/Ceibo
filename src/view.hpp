#ifndef VIEW_H
#define VIEW_H

#include <GLFW/glfw3.h>
#include <vector>

class View {
public:
    void render(const std::vector<float>& vertices);
};

#endif // VIEW_H
