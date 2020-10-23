#include <iostream>
#include <string>
#include <string.h>

#include <benchmark/benchmark.h>

#include "ximd_ascii.hpp"

using namespace ximd;

void gen_long_test_str(char* buff)
{
  const char* test_str = "a (noT So) Carefully conStruCted test sTr";
  size_t len = strlen(test_str);
  for (size_t i=0; i < 4096 / len; ++i)
  {
    strcpy(buff + i * len, test_str);
  }
}

static void BM_ToLowerStd(benchmark::State& state)
{
  char buff[4096];
  gen_long_test_str(buff);
  for (auto _ : state)
  {
    to_lower_std(buff);
  }
}

static void BM_ToLowerNaive(benchmark::State& state)
{
  char buff[4096];
  gen_long_test_str(buff);
  for (auto _ : state)
  {
    to_lower_naive(buff);
  }
}

static void BM_ToLower64(benchmark::State& state)
{
  char buff[4096];
  gen_long_test_str(buff);
  for (auto _ : state)
  {
    to_lower_64(buff);
  }
}

BENCHMARK(BM_ToLowerStd);
BENCHMARK(BM_ToLowerNaive);
BENCHMARK(BM_ToLower64);

BENCHMARK_MAIN();
