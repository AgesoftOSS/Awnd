#include "AwndButton.h"

Awnd::Button::Button(int x, int y, int width, int height, LPCWSTR text, HWND hwnd, HMENU Id)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->text = text;
	this->hwnd = hwnd;
	this->Id = Id;
}

void Awnd::Button::append()
{
	CreateWindowW(L"BUTTON", this->text,
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		this->x, this->y, this->width, this->height,
		this->hwnd, (HMENU)this->Id, (HINSTANCE)GetWindowLong(this->hwnd, GWLP_HINSTANCE), NULL);
}
