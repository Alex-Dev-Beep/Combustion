#include "engine.hpp"

#include <iostream>

int main() {
    Engine engine;

    std::cout << "Initializing Engine..." << std::endl;

    if (engine.Initialize()) {
        engine.Run();
    }

    return 0;
}