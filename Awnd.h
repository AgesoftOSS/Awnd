/*
	Awnd.h

	Awnd, a C++ Framework.
	Copyright Agesoft 2021 - 2023


	Here at Agesoft we like to use our own products and really avoid third party libraries that can bloat your project.
	That's why we made Awnd. a framework to create Win32 Applications easily.

	I doubt someone reads this all!

	If you want the specific features read this:
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	These Features work standalone:
	"Random.h" - Pseudo-RNG

	Poem:
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	I'm a toy. everyone loves toys right?
	even coders. they like to code anything

	Suffer less. code more.
	chop chop, i'll make you a good coder.
	use me and you will be satisfied.

	but don't expect me to be as good as Adobe.
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	Author(s):
	~~~~~~~~~~~~~~~~~~~~~~~~
	Copy05

*/

#pragma region Includes
#pragma once

// Awnd Includes
#include "AwndLabel.h"
#include "AwndButton.h"
#include "AwndTextBox.h"
#include "Application.h"

// C/C++ Includes
#include <string>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <Windows.h>
#pragma endregion

#pragma region Macros

#define OnClick(wParam, ID) (LOWORD(wParam) == ID)
#define DebugPrint(value) printf(value);

#pragma endregion


#pragma region Awnd Namespace
namespace Awnd {

	// Easy Color
	class Color {
	public:
		// constructors
		Color() : r(0x00), g(0x00), b(0x00) {};
		Color(int red, int green, int blue) : r(red), g(green), b(blue) {};

		// operators
		friend std::ostream& operator<<(std::ostream& out, const Color& c);

		// methods
		void SetColor(int r, int g, int b) {
			this->r = r;
			this->g = g;
			this->b = b;
		}

		int GetRed() const { return r; }
		int GetGreen() const { return g; }
		int GetBlue() const { return b; }

		int r, g, b;
	};

	class Vector2 {
	public:
		Vector2(float x, float y) {
			this->x = x;
			this->y = y;
		}

		friend std::ostream& operator<<(std::ostream& out, const Vector2& v);

		// Returns true if the vector has the same values like the passed vector ones
		bool Equals(const Vector2& other) {
			if (other.x == this->x && other.y == this->y)
				return true;
			else
				return false;
		}

		std::string ToString() {
			return std::to_string(x) + ',' + std::to_string(y);
		}

		float x, y;
	};

	class Vector3 {
	public:
		Vector3(float x, float y, float z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		friend std::ostream& operator<<(std::ostream& out, const Vector3& v);

		// Returns true if the vector has the same values like the passed vector ones
		bool Equals(const Vector3& other) {
			if (other.x == this->x && other.y == this->y && other.z == this->z)
				return true;
			else
				return false;
		}

		std::string ToString() {
			return std::to_string(x) + ',' + std::to_string(y) + ',' + std::to_string(z);
		}

		float x, y, z;
	};

	// Operators

	inline std::ostream& operator<<(std::ostream& out, const Color& c) { out << c.r << ", " << c.g << ", " << c.b; return out; };
	inline std::ostream& operator<<(std::ostream& out, const Vector2& v) { out << v.x << ", " << v.y; return out; };
	inline std::ostream& operator<<(std::ostream& out, const Vector3& v) { out << v.x << ", " << v.y << ", " << v.z; return out; };


	// Methods
}
#pragma endregion

// Awnd Base Class
class AwndApp
{
protected:
	virtual void onApplicationCreate(float e_Time) { exit(0x00); };
	virtual void onApplicationCreate() { exit(0x00); };

	// Hides the Window
	void HideConsole() { ShowWindow(GetConsoleWindow(), SW_HIDE); };
	long GetScreenWidth() { return GetSystemMetrics(SM_CXSCREEN); };
	long GetScreenHeight() { return GetSystemMetrics(SM_CYSCREEN); };
};
