#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>

#include "engine.h""
#include "renderer_gl.hpp"


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        RECT r; GetClientRect(hWnd, &r);
        HBRUSH brush = CreateSolidBrush(RGB(30, 30, 36)); // dark bg
        FillRect(hdc, &r, brush);
        DeleteObject(brush);
        EndPaint(hWnd, &ps);
    } return 0;
    case WM_DESTROY: PostQuitMessage(0); return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow) {
    AllocConsole();

    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);
    freopen_s(&f, "CONOUT$", "w", stderr);

    const wchar_t* kClass = L"CoreDbgWnd";
    WNDCLASSEXW wc{ sizeof(WNDCLASSEXW) };
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInst;
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = kClass;
    RegisterClassExW(&wc);

    static RendererGL renderer;
    static Engine engine(&renderer);

    std::cout << "Core Debug Window starting..." << std::endl;

    HWND hwnd = CreateWindowExW(
        0, kClass, L"Core Debug Window",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 800,
        nullptr, nullptr, hInst, nullptr);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // main loop
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        engine.update();
        // TODO: call into your core tick/render here if needed
    }
    return (int)msg.wParam;
}
