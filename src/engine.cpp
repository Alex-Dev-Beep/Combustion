#include "engine.hpp"
#include "window/window.hpp"

#include <d3d11.h>
#include <dxgi.h>

#include <iostream>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")

Engine::Engine()
    : m_hInstance(GetModuleHandleW(nullptr)),
      m_applicationName(L"BorealEngine"),
      m_hwnd(nullptr)
{
}

Engine::~Engine()
{
    if (m_hwnd)
    {
        DestroyWindow(m_hwnd);
        m_hwnd = nullptr;
    }

    if (m_applicationName)
    {
        UnregisterClassW(
            m_applicationName,
            m_hInstance
        );
    }
}

bool Engine::Initialize()
{
    if (!CreateDXWindow(
        L"Boreal Engine",
        100,
        100,
        1280,
        720))
    {
        return false;
    }

    std::cout
        << "Engine initialized successfully!"
        << std::endl;

    return true;
}

void Engine::Run()
{
    MSG msg = {};

    while (msg.message != WM_QUIT)
    {
        while (PeekMessageW(
            &msg,
            nullptr,
            0,
            0,
            PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                break;

            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }

        while (!keyboard.isCharBufferEmpty())
        {
            const unsigned char character =
                keyboard.readChar();

            std::cout
                << "Char: "
                << static_cast<char>(character)
                << " ("
                << static_cast<int>(character)
                << ")"
                << std::endl;
        }

        while (!keyboard.isKeyBufferEmpty())
        {
            const KeyboardEvent event =
                keyboard.readKey();

            if (!event.isValid())
                continue;

            const unsigned char key =
                event.getKeyCode();
        }

        while (!engine.mouse.EventBufferIsEmpty())
	    {
	    	MouseEvent me = mouse.ReadEvent();

            if (static_cast<int>(me.GetType()) == 1) {
                std::cout << "Mouse: LMB" << std::endl;
            } else if (static_cast<int>(me.GetType()) == 2) {
                std::cout << "Mouse: RMB Pressed" << std::endl;
            } else if (static_cast<int>(me.GetType()) == 3) {
                std::cout << "Mouse: RMB Released" << std::endl;
            } else if (static_cast<int>(me.GetType()) == 4) {
                std::cout << "Mouse: MMB Pressed" << std::endl;
            } else if (static_cast<int>(me.GetType()) == 5) {
                std::cout << "Mouse: MMB Released" << std::endl;
            }
	    }

        // Update();
        // Render();
    }
}

bool Engine::CreateDXWindow(
    const wchar_t* title,
    int x,
    int y,
    int width,
    int height)
{
    WNDCLASSEXW wc = {};

    m_applicationName = L"BorealEngine";

    wc.cbSize = sizeof(WNDCLASSEXW);
    wc.style =
        CS_HREDRAW |
        CS_VREDRAW |
        CS_OWNDC;

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = m_hInstance;
    wc.hCursor = LoadCursor(
        nullptr,
        IDC_ARROW
    );

    wc.lpszClassName =
        m_applicationName;

    wc.hIcon = LoadIcon(
        nullptr,
        IDI_APPLICATION
    );

    wc.hIconSm = wc.hIcon;

    wc.hbrBackground =
        static_cast<HBRUSH>(
            GetStockObject(BLACK_BRUSH)
        );

    if (!RegisterClassExW(&wc))
    {
        std::cout
            << "RegisterClassExW failed: "
            << GetLastError()
            << std::endl;

        return false;
    }

    m_hwnd = CreateWindowExW(
        0,
        m_applicationName,
        title,
        WS_OVERLAPPEDWINDOW,
        x,
        y,
        width,
        height,
        nullptr,
        nullptr,
        m_hInstance,
        nullptr
    );

    if (!m_hwnd)
    {
        std::cout
            << "CreateWindowExW failed: "
            << GetLastError()
            << std::endl;

        return false;
    }

    ShowWindow(m_hwnd, SW_SHOW);
    UpdateWindow(m_hwnd);

    SetForegroundWindow(m_hwnd);
    SetFocus(m_hwnd);

    return true;
}