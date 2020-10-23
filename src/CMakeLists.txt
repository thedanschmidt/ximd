file(GLOB HEADER_LIST "../inc/*.h")
file(GLOB SRC_LIST "*.cpp")

add_library(ximd_library ${SRC_LIST} ${HEADER_LIST})
target_include_directories(ximd_library PUBLIC "../inc")
target_compile_features(ximd_library PUBLIC cxx_std_11)
