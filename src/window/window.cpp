#include "window.hpp"

LRESULT CALLBACK WindowProc(
    HWND hwnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam)
{
    switch (uMsg)
    {
    // =========================
    // Keyboard
    // =========================

    case WM_KEYDOWN:
    {
        unsigned char key =
            static_cast<unsigned char>(wParam);

        const bool wasAlreadyDown =
            (lParam & (1LL << 30)) != 0;

        if (engine.keyboard.isKeysAutoRepeat() || !wasAlreadyDown)
        {
            engine.keyboard.onKeyPressed(key);
        }

        return 0;
    }

    case WM_KEYUP:
    {
        unsigned char key =
            static_cast<unsigned char>(wParam);

        engine.keyboard.onKeyReleased(key);

        return 0;
    }

    case WM_CHAR:
    {
        engine.keyboard.onChar(
            static_cast<unsigned char>(wParam)
        );

        return 0;
    }

    // =========================
    // Window
    // =========================

    case WM_SETFOCUS:
        return 0;

    case WM_KILLFOCUS:
        return 0;

    case WM_CLOSE:
        DestroyWindow(hwnd);
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    // =========================
    // Mouse
    // =========================

    case WM_MOUSEMOVE:
    {
        const int x = static_cast<short>(LOWORD(lParam));
        const int y = static_cast<short>(HIWORD(lParam));

        engine.mouse.OnMouseMove(x, y);

        return 0;
    }

    case WM_LBUTTONDOWN:
    {
        const int x = static_cast<short>(LOWORD(lParam));
        const int y = static_cast<short>(HIWORD(lParam));

        engine.mouse.OnLeftPressed(x, y);

        return 0;
    }

    case WM_RBUTTONDOWN:
    {
        const int x = static_cast<short>(LOWORD(lParam));
        const int y = static_cast<short>(HIWORD(lParam));

        engine.mouse.OnRightPressed(x, y);

        return 0;
    }

    case WM_MBUTTONDOWN:
    {
        const int x = static_cast<short>(LOWORD(lParam));
        const int y = static_cast<short>(HIWORD(lParam));

        engine.mouse.OnMiddlePressed(x, y);

        return 0;
    }

    case WM_LBUTTONUP:
    {
        const int x = static_cast<short>(LOWORD(lParam));
        const int y = static_cast<short>(HIWORD(lParam));

        engine.mouse.OnLeftReleased(x, y);

        return 0;
    }

    case WM_RBUTTONUP:
    {
        const int x = static_cast<short>(LOWORD(lParam));
        const int y = static_cast<short>(HIWORD(lParam));

        engine.mouse.OnRightReleased(x, y);

        return 0;
    }

    case WM_MBUTTONUP:
    {
        const int x = static_cast<short>(LOWORD(lParam));
        const int y = static_cast<short>(HIWORD(lParam));

        engine.mouse.OnMiddleReleased(x, y);

        return 0;
    }

    case WM_MOUSEWHEEL:
    {
        const int x = static_cast<short>(LOWORD(lParam));
        const int y = static_cast<short>(HIWORD(lParam));

        if (GET_WHEEL_DELTA_WPARAM(wParam) > 0)
        {
            engine.mouse.OnWheelUp(x, y);
        }
        else if (GET_WHEEL_DELTA_WPARAM(wParam) < 0)
        {
            engine.mouse.OnWheelDown(x, y);
        }

        return 0;
    }
    }

    return DefWindowProcW(
        hwnd,
        uMsg,
        wParam,
        lParam
    );
}