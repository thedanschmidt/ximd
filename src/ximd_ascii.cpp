#include "ximd_ascii.hpp"
#include "debug.hpp"

namespace ximd
{

void to_lower_std(char* str, size_t length)
{
  while (length > 0)
  {
    *str = static_cast<char>(std::tolower(*str));
    ++str;
    --length;
  }
}

void to_lower_naive(char* str, size_t length)
{
  while (length > 0)
  {
    if (*str >= 'A' && *str <= 'Z')
    {
      *str ^= (1 << 5);
    }
    ++str;
    --length;
  }
}

void to_lower_64(char* str, size_t length)
{
  static const __m64 max64 = _mm_set1_pi8(0xFF);
  static const __m64 capA = _mm_set1_pi8('A' - 1);
  static const __m64 capZ = _mm_set1_pi8('Z' + 1);
  static const __m64 lowerm = _mm_set1_pi8(1 << 5); // 'A' and 'a' differ in 5th bit

  __m64 buffer = _m_from_int64(0);
  while (length >= 8)
  {
    // TODO reduce operations here
    buffer = *(reinterpret_cast<__m64*>(str));
    __m64 amask = _m_pcmpgtb(buffer, capA);
    __m64 bmask = _m_pcmpgtb(capZ, buffer);
    amask = _m_pand(amask, bmask);
    amask = _m_pand(amask, lowerm);
    buffer = _m_por(amask, buffer);
    _m_maskmovq(buffer, max64, str);
    str += 8;
    length -= 8;
  }
  to_lower_naive(str, length);
}

void to_lower_128(char* str, size_t length) 
{
  static const __m128i max128 = _mm_set1_epi8(0xFF);
  static const __m128i capA = _mm_set1_epi8('A' - 1);
  static const __m128i capZ = _mm_set1_epi8('Z' + 1);
  static const __m128i lowerm = _mm_set1_epi8(1 << 5); // 'A' and 'a' differ in 5th bit

  __m128i buffer = _mm_set1_epi8(0);
  while (length >= 16)
  {
    // TODO reduce operations here
    buffer = *(reinterpret_cast<__m128i*>(str));
    __m128i amask = _mm_cmpgt_epi8(buffer, capA);
    __m128i bmask = _mm_cmpgt_epi8(capZ, buffer);
    amask = _mm_and_si128(amask, bmask);
    amask = _mm_and_si128(amask, lowerm);
    buffer = _mm_or_si128(amask, buffer);
    _mm_maskmoveu_si128(buffer, max128, str);
    str += 16;
    length -= 16;
  }
  to_lower_naive(str, length);
}

} // ns ximd
