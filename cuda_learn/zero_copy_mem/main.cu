#include <iostream>
#include "cuda_runtime_api.h"
#include "device_launch_parameters.h"
#include "cuda.h"
#include "cuda_device_runtime_api.h"

/*
 * Kernel function accesses data elements from a zero copy memory
 */
__global__ void zero_copy_kernel(float* dev_data)
{
    dev_data[threadIdx.x] *= 2;

}

void fill_host_data(float* h_data, int size)
{
    for(int i = 0; i < size; i++)
    {
        h_data[i] = i;
    }
}

void print_zero_copy_mem_data(float* mapped_mem, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("mem[%d] = %f\n", i, mapped_mem[i]);
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    //
    // setup
    float* h_data;
    int n_bytes = sizeof(float) * 100; // 100 float numbers

    // allocate zero-copy mem on host
    cudaError_t err = cudaHostAlloc((void**)&h_data, n_bytes, cudaHostAllocMapped);
    printf("%s\n", cudaGetErrorString(err));

    // fill data
    fill_host_data(h_data, 100);

    // print out
    print_zero_copy_mem_data(h_data, 100);

    // get a device side pointer to the mapped data
    float* dev_ptr;
    err = cudaHostGetDevicePointer((void**)&dev_ptr, h_data, 0);
    printf("%s\n", cudaGetErrorString(err));

    // launch kernel, NOTE: we do not need explicit memory copying now
    zero_copy_kernel<<<1, 100>>>(dev_ptr);
    cudaDeviceSynchronize();

    // now print - kernel should have multiplied every entry by 2 in place
    print_zero_copy_mem_data(h_data, 100);


    cudaFree(dev_ptr);
    cudaFreeHost(h_data);
    cudaDeviceReset();



    return 0;
}
