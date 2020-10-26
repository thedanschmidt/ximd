#pragma once

// implementations of common ASCII operations with explict SIMD
#include <cstdint>
#include <immintrin.h>

namespace ximd
{

// simple reference implementation for baseline
void to_lower_std(char* str, size_t length);
void to_lower_naive(char* str, size_t length);
void to_lower_64(char* str, size_t length);
void to_lower_128(char* str, size_t length);

// TODO auto select based on detected SIMD support
//const auto& to_lower = to_lower_naive;

} // ns ximd
