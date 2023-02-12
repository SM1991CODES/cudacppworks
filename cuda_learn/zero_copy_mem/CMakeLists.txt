cmake_minimum_required(VERSION 3.22)
project(zero_copy_mem CUDA)

set(CMAKE_CUDA_STANDARD 14)

add_compile_options(-G)

add_executable(zero_copy_mem main.cu)

set_target_properties(zero_copy_mem PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)
