cmake_minimum_required(VERSION 3.23)
project(mem_model CUDA)

set(CMAKE_CUDA_STANDARD 14)
#set(CMAKE_CUDA_COMPILER "/usr/local/cuda/bin/nvcc" -g)
#set(CMAKE_CUDA_ARCHITECTURES 75)
add_executable(mem_model main.cu)

set_target_properties(mem_model PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON
        CUDA_ARCHITECTURES "50;75")
