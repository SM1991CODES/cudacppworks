#include <iostream>
#include <stdio.h>

using namespace std;


typedef unsigned short int i_USHORT;
/*
 * Function returns result of some basic maths operation on the two passed numbers based on
 * choice
 */
int getMathResult(int a, int b, int8_t choice)
{
    switch (choice) {
        case 1:
            return a+b;
            break;
        case 2:
            return a-b;
            break;
        case 3:
            return a*b;
            break;
        case 4:
            return a/b;
            break;
        case 5:
            return a%b;
            break;
    }
    //
    return -1;
}


void testWrapAround(i_USHORT x)
{
    cout << sizeof (i_USHORT) << endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    printf("Hello World\n");
    //
    i_USHORT x = 250;
    testWrapAround(x);
    int a, b;
    int8_t choice;
    printf("Enter two numbers ->\n");
    std::cin >> a;
    std::cin >> b;
    printf("[1: add, 2:subtract, 3:multiply, 4:divide, 5:remainder]\nEnter choice\n");
    cin >> choice;

    auto res = getMathResult(a, b, choice);
    cout << "Result : " << res << endl;

    cout << sizeof(choice) << endl;

    return 0;
}
