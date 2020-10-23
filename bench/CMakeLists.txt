add_executable(ximdbench main.cpp)
target_compile_features(ximdbench PRIVATE cxx_std_11)

set(BENCHMARK_ENABLE_TESTING NO)
include(FetchContent)
FetchContent_Declare(googlebenchmark
                     GIT_REPOSITORY https://github.com/google/benchmark)
FetchContent_MakeAvailable(googlebenchmark)

target_link_libraries(ximdbench PRIVATE ximd_library benchmark::benchmark)
