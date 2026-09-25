#pragma once

#include <windows.h>

#include "../engine.hpp"

extern Engine engine;

LRESULT CALLBACK WindowProc(
    HWND hwnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam
);