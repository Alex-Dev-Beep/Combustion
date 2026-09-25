#include "engine.hpp"

#include <iostream>

Engine engine;

int main() {


    std::cout << "Initializing Engine..." << std::endl;

    if (engine.Initialize()) {
        engine.Run();
    }

    return 0;
}