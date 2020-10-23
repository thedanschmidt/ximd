#include "ximd_ascii.hpp"
#include "debug.hpp"

namespace ximd
{

void to_lower_std(char* str)
{
  while (*str != '\0')
  {
    *str = static_cast<char>(std::tolower(*str));
    ++str;
  }
}

void to_lower_naive(char* str)
{
  while (*str != '\0')
  {
    if (*str >= 'A' && *str <= 'Z')
    {
      *str ^= (1 << 5);
    }
    ++str;
  }
}

void to_lower_64(char* str)
{
  uint8_t counter = 0;
  __m64 buffer = _m_from_int64(0);
  static const __m64 max64 = _mm_set1_pi8(0xFF);
  static const __m64 capA = _mm_set1_pi8('A' - 1);
  static const __m64 capZ = _mm_set1_pi8('Z' + 1);
  static const __m64 lowerm = _mm_set1_pi8(1 << 5); // 'A' and 'a' differ in 5th bit
  while (*str != '\0')
  {
    ++counter;
    if (counter == 8)
    {
      counter = 0;
      buffer = *(reinterpret_cast<__m64*>(str - 8));
      __m64 amask = _m_pcmpgtb(buffer, capA);
      __m64 bmask = _m_pcmpgtb(capZ, buffer);
      amask = _m_pand(amask, bmask);
      amask = _m_pand(amask, lowerm);
      buffer = _m_por(amask, buffer);
      _m_maskmovq(buffer, max64, str - 8);
    }
    ++str;
  }
  // go back and finish
  str -= counter;
  to_lower_naive(str);
}

void to_lower_128(char* str) {}

} // ns ximd
