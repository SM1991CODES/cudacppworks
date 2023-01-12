/*
 * Day 18: Creating and using namespaces
 */


#include <iostream>
#include "sensor1.h"
#include "sensor2.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    //
    sensor1::setParam(8, 9.7);
    sensor2::setParam(8, 8.8);
    return 0;
}
