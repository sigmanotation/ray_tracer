cmake_minimum_required(VERSION 3.15)
project(rt_weekend VERSION 1.0)

# Specify the C++ standard
add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_23)

add_executable(rt main.cpp)
target_link_libraries(rt PUBLIC compiler_flags)

target_include_directories(rt PUBLIC "${PROJECT_SOURCE_DIR}/headers")