#include <iostream>
#include "cuda_runtime_api.h"
#include "cuda_device_runtime_api.h"
#include "stdio.h"
#include "device_launch_parameters.h"

__global__ void pinnedMemoryKernel(float* dataPtr)
{
    printf("thread id -> %d, data -> %f\n", threadIdx.x, dataPtr[threadIdx.x]);
}


void loadHostData(float* h_ptr, int size)
{
    for(int i = 0; i < size; i++)
    {
        h_ptr[i] = i * 2;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    float *h_data;
    float *d_data;
    size_t data_size_bytes = sizeof(float ) * 100;
    cudaError_t err = cudaMallocHost((void **) &h_data, data_size_bytes); // allocate pinned mem on host
    std::cout << cudaGetErrorString(err) << std::endl;
    //
    loadHostData(h_data, 100);
    //
    cudaMalloc((float **)&d_data, sizeof(float) * 100); // allocate device mem
    cudaMemcpy(d_data, h_data, sizeof(float ) * 100, cudaMemcpyHostToDevice); // copy pinned mem to device mem
    //
    pinnedMemoryKernel<<<1, 100>>>(d_data);
    cudaDeviceSynchronize();
    //
    cudaDeviceReset();
    //
    cudaFreeHost(h_data);
    cudaFree(d_data);
    return 0;
}
