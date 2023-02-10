#pragma once
#include <Windows.h>

namespace Awnd {
	class Button
	{
	public:
		Button() {};
		Button(int x, int y, int width, int height, LPCWSTR text, HWND hwnd, HMENU Id);
		int x, y, width, height;
		LPCWSTR text;
		HWND hwnd;
		HMENU Id;

		// Appends the control to the frame.
		void append();
	};
}

