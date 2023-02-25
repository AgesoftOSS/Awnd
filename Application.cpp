/*
	Application.cpp / Application.h
	The file that contains the code for the Application.

	(c) Agesoft 2021 - 2023
	
	Authors:
	Copy05 (https://github.com/Copy05)
	ConstantesInt (https://github.com/ConstantesInt)
*/

#include "Application.h"
#include "Awnd.h"

#define Render(int) Sleep(int);

const wchar_t* class_name = L"AgesoftAwndFrame";

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		// Executes when the Application starts.
		Awnd::ComponentHandler(hWnd);
		break;
	case WM_COMMAND:
		Awnd::CommandHandler(wParam);
		break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0x00);
		return 0x00;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

Application::Application(LPCWSTR windowsTitle, bool fullScreen, int rectwidth, int rectheight) : w_hInstance(GetModuleHandle(nullptr))
{
	DWORD style;
	const wchar_t* windowTitle = windowsTitle;

	WNDCLASS winClass = {};
	winClass.lpszClassName = class_name;
	winClass.hInstance = w_hInstance;
	winClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	winClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 0x01);
	winClass.lpfnWndProc = WindowProc;

	RegisterClass(&winClass);

	if (fullScreen) {
		rectwidth = GetSystemMetrics(SM_CXSCREEN);
		rectheight = GetSystemMetrics(SM_CYSCREEN);
		style = WS_POPUP | WS_VISIBLE;
	}

	else {
		style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU | WS_VISIBLE | WS_OVERLAPPEDWINDOW;
	}

	RECT rect;
	rect.left = 0xFA;
	rect.top = 0xFA;
	rect.right = rect.left + rectwidth;
	rect.bottom = rect.top + rectheight;

	AdjustWindowRect(&rect, style, false);

	w_hwnd = CreateWindowEx(0x00, class_name, windowTitle, style, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, w_hInstance, NULL);

	ShowWindow(w_hwnd, SW_SHOW);
}

Application::~Application()
{
	UnregisterClass(class_name, w_hInstance);
}

void Application::runWindow(int renderTime)
{
	bool running = true;
	while (running)
	{
		if (!this->processMessages())
			running = false;

		// Rendering The Window
		Render(renderTime);
	}

	delete this;
}

bool Application::processMessages()
{
	MSG msg = {};
	while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE))
	{
		if (msg.message == WM_QUIT)
			return false;

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return true;
}
