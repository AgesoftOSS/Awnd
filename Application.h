/*
	Application.h
	The header file that contains the Application.

	(c) Agesoft 2021 - 2023
*/

#pragma once
#include <Windows.h>

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

namespace Awnd {
	// Implement this function to handle GUI Components / Windows
	void ComponentHandler(HWND hwnd);

	// Implement this function to handle Component Commands.
	void CommandHandler(WPARAM wParam);
}

class Application {
public:
	Application(LPCWSTR windowsTitle, bool fullScreen, int rectwidth = 640, int rectheight = 480);
	~Application();
	void runWindow(int renderTime = 10);

	// Don't use it. it's a part of the frame rendering
	bool processMessages();
private:
	HINSTANCE w_hInstance;
	HWND w_hwnd;
};