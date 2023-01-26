/*
 * Day 19: Templates
 */

#include <iostream>
#include <cstring>

template<class T>
class Tensor
{
public:
    //
    Tensor(int dimx, int dimy, int dimz);
    //
    T readFrom(int x, int y, int z);
    //
    void writeTo(int x, int y, int z, T val);

private:
    T *data; // holds the data elements of the array
    int rows;
    int cols;
    int channels;
};

template<class T>
Tensor<T>::Tensor(int dimx, int dimy, int dimz)
{
    printf("Creating tensor of dims %d, %d, %d\n", dimx, dimy, dimz);
    this->rows = dimx;
    this->cols = dimy;
    this->channels = dimz;
    this->data = (T*) malloc(sizeof(T) * dimx * dimy * dimz);
    memset(this->data, 0, sizeof(this->data));
}

template<class T>
void Tensor<T>::writeTo(int x, int y, int z, T val)
{
    auto gid = this->rows * this->cols * z + this->cols * x + y;
    this->data[gid] = val;
}

/*
 * A template function that can compute sum of different types of input
 */
template<class V>
V sum(V var1, V var2)
{
    return var1 + var2;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    //
    Tensor<uint16_t> tens1(5, 5, 3);
    tens1.writeTo(3, 3, 0, 9);
    //
    std::cout << sum(5, 5) << std::endl;
    std::cout << sum(6.5, 8.9) << std::endl;
    return 0;
}
