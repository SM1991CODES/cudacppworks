#include <iostream>
#include <stdio.h>

typedef int (*pSUM_NEW) (int, int);


int sum(int a, int b)
{
    return a+b;
}

void printSum(int (*pSum) (int, int), int a, int b)
{
    printf("Sum using function pointer as param -> %d\n", pSum(a, b));
}

int main()
{
    int (*pSumFunc) (int, int);
    pSumFunc = sum;
    printSum(pSumFunc, 10, 20);

    pSUM_NEW ptr = sum;
    printf("Sum using typedef -> %d\n", ptr(50, 50));

    return 0;
}