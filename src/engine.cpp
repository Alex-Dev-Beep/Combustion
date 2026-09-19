#include "engine.hpp"
#include <d3d11.h>
#include <dxgi.h>

#include <iostream>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

Engine::Engine()
    : m_hInstance(GetModuleHandle(NULL)), m_applicationName(L"BorealEngine"), m_hwnd(nullptr) {
}

Engine::~Engine() {
    UnregisterClass(m_applicationName, m_hInstance);
}

bool Engine::Initialize() {
    if (!CreateDXWindow(L"Boreal Engine", 100, 100, 1280, 720)) {
        return false;
    }

    std::cout << "Engine initialized succesfully!" << std::endl;
    return true;
}

void Engine::Run() {
    MSG msg = {};
    ZeroMemory(&msg, sizeof(MSG));
    while (msg.message != WM_QUIT) {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else {
            
        }
    }
}

bool Engine::CreateDXWindow(const wchar_t* title, int x, int y, int width, int height) {
    WNDCLASSEX wc = {};

    m_applicationName = title;

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = m_hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = m_applicationName;
    wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
    wc.hIconSm = wc.hIcon;
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);

    if (!RegisterClassEx(&wc)) {
        return false;
    }

    m_hwnd = CreateWindowEx(
        0,
        m_applicationName,
        title,
        WS_OVERLAPPEDWINDOW,
        x, y, width, height,
        nullptr,
        nullptr,
        m_hInstance,
        nullptr
    );

    if (!m_hwnd) {
        return false;
    }

    ShowWindow(m_hwnd, SW_SHOW);
    SetForegroundWindow(m_hwnd);
    SetFocus(m_hwnd);
    return true;
}