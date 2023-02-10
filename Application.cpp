/*
	Application.cpp / Application.h
	The file that contains the code for the Application.

	(c) Agesoft 2021 - 2023
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
	case WM_PAINT:
		// Unused for now.
		break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

// Das ist ein konstruktor dieser Construktor erstellt Die Fenster von dem Programm
// Parametern sind Fensterbreite und höhe. Fenster Titel und ob es Vollbild sein soll oder nicht
Application::Application(LPCWSTR windowsTitle, bool fullScreen, int rectwidth, int rectheight) : w_hInstance(GetModuleHandle(nullptr))
{
	// Dieser Variable gestalltet das fenster
	DWORD style;
	// Das ist das Fenster Titel
	const wchar_t* windowTitle = windowsTitle;

	// Hier wird das Fenster definiert und erstellt
	WNDCLASS winClass = {};
	winClass.lpszClassName = class_name;
	winClass.hInstance = w_hInstance;
	winClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	winClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // Hintergrund von den Fenster
	winClass.lpfnWndProc = WindowProc; // Die Graphische oberfläche wird in WindowProc erstellt

	RegisterClass(&winClass);

	// Wenn fullscreen True ist dann erscheint das fenster in Vollbild.
	if (fullScreen) {
		rectwidth = GetSystemMetrics(SM_CXSCREEN); // Gibt den bildschirmbreite 
		rectheight = GetSystemMetrics(SM_CYSCREEN); // Gibt den bildschirmhöhe
		style = WS_POPUP | WS_VISIBLE;
	}

	else {
		style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU | WS_VISIBLE | WS_OVERLAPPEDWINDOW;
	}

	RECT rect;
	rect.left = 250;
	rect.top = 250;
	rect.right = rect.left + rectwidth;
	rect.bottom = rect.top + rectheight;

	AdjustWindowRect(&rect, style, false);

	w_hwnd = CreateWindowEx(0, class_name, windowTitle, style, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, w_hInstance, NULL);

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