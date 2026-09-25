#pragma once

#include <windows.h>

#include "input/keyboard/keyboard.hpp"
#include "input/mouse/mouse.hpp"

struct Engine {
public:
    Engine(); 
    ~Engine();
    void Run();
    bool Initialize();

    Keyboard keyboard;
    Mouse mouse;

private:
    bool CreateDXWindow(const wchar_t* title, int x, int y, int width, int height);

    const wchar_t* m_applicationName;
    HINSTANCE m_hInstance;
    HWND m_hwnd;
};