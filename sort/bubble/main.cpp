// main.cpp
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include "bubbleSort.h"
static void initRandom(int list[], int n, int max = 100)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        list[i] = rand() % max;
}
static void printArr(int arr[], int n, const char* str = "Array")
{
    printf("%s = ", str);
    for (int i = 0; i < n; i++)
        printf("%3d", arr[i]);
    printf("\n");
}

int main(void)
{
    int n = 16;
    int list[n];
    initRandom(list, n);
    printArr(list, n, "Original ");
    bubbleSort(list, n);
    printArr(list, n, "Bubble Sort ");

    return 0;
}