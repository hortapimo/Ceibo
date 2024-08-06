#include "model.hpp"
#include "view.hpp"
#include "controller.hpp"


int main() {
    Model model;
    View view;
    Controller controller(model, view);
// ljvbsldjfvblsdfkj
    controller.run();

    return 0;
}
