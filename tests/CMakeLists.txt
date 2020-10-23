add_executable(tests main.cpp)
target_compile_features(tests PRIVATE cxx_std_11)
target_link_libraries(tests PRIVATE ximd_library)
