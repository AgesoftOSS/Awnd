/*
	Random.h
	The header file that contains the Random class.

	(c) Agesoft 2021 - 2023
*/

#pragma once
#include <cmath>
#include <ctime>
#include <cstdint>

namespace Awnd {

	// Required to make pseudo-random numbers
	void EnableRandom() {
		srand((unsigned)time(0));
	}

	class Random {
	public:
		// Returns a random int
		static int Integer() {
			return rand();
		}

		// Returns a random uInt
		static uint32_t UInt() {
			return rand();
		}

		// Returns a random float
		static float Float() {
			return static_cast<float>(rand());
		}
	};
}