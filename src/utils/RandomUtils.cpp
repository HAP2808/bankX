#include "utils/RandomUtils.h"

#include <random>
#include <stdexcept>

/// @brief Generic function to generate an N-digit random number.
/// @param numDigits 
/// @return Return the N-digit random number.
long long generateNDigitID(int numDigits) {
    // A 64-bit integer can safely hold up to 18 digits.
    if (numDigits < 1 || numDigits > 18) {
        throw std::invalid_argument("Number of digits must be between 1 and 18.");
    }

    // 1. Calculate the minimum and maximum boundaries dynamically
    // Using a loop avoids the precision issues sometimes caused by floating-point std::pow()
    long long minVal = 1;
    for (int i = 1; i < numDigits; ++i) {
        minVal *= 10;
    }
    long long maxVal = minVal * 10 - 1;

    // Special case: if generating a 1-digit number, you usually want to include 0
    if (numDigits == 1) {
        minVal = 0;
    }

    // 2. Setup the hardware seed and 64-bit random number generator
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<long long> dist(minVal, maxVal);

    // 3. Generate and return the number
    return dist(gen);
}