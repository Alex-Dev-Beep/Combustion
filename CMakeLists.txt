cmake_minimum_required(VERSION 3.20)
project(Boreal LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Boreal
    src/main.cpp
    src/engine.cpp
    src/engine.hpp
)

target_compile_definitions(Boreal PRIVATE
    UNICODE
    _UNICODE
)

target_link_libraries(Boreal PRIVATE
    d3d11
    dxgi
    d3dcompiler
)