#include "AwndLabel.h"

Awnd::Label::Label(int x, int y, int width, int height, LPCWSTR text, HWND hwnd, HMENU Id)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->text = text;
	this->hwnd = hwnd;
	this->Id = Id;
}

void Awnd::Label::append()
{
	CreateWindowW(L"STATIC", this->text,
		WS_CHILD | WS_VISIBLE,
		this->x, this->y, this->width, this->height,
		this->hwnd, (HMENU)this->Id, (HINSTANCE)GetWindowLong(this->hwnd, GWLP_HINSTANCE), NULL);
}
