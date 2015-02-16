#include "view.h"
#include <iostream>

int main(int argc, char** argv) {
    Model model(8,8);
    View view("Concentration!", 1024, 768);
    view.show(&model);
    std::cout << "hi";
    /*
    Controller c;
    c.loop();
    */
    return 0;
}
