/*
	AwndTextBox.cpp
	The header file that contains the TextBox Control.

	(c) Agesoft 2021 -2 023
*/

#include "AwndTextBox.h"

Awnd::TextBox::TextBox(int x, int y, int width, int height, LPCWSTR text, HWND hwnd, HMENU Id)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->text = text;
	this->hwnd = hwnd;
	this->Id = Id;
}

void Awnd::TextBox::append()
{
	CreateWindowW(L"EDIT", this->text,
		WS_CHILD | WS_VISIBLE,
		this->x, this->y, this->width, this->height,
		this->hwnd, (HMENU)this->Id, (HINSTANCE)GetWindowLong(this->hwnd, GWLP_HINSTANCE), NULL);
}
