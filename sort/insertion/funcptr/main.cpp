// main.cpp
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include "insertionSortFn.h"
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
    int size = 16;
    int list[size];
    int org[size];
    initRandom(list, size);
    printArr(list, size, "Original ");

    insertionSortFn(list, size, ascend);
    printArr(list, size, "Insertion-Ascend");

    insertionSortFn(list, size, descend);
    printArr(list, size, "Insertion-Descend");

    return 0;
}