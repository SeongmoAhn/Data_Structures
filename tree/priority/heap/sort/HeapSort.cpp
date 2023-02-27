// HeapSort.cpp
#include "HeapSort.h"
#include <cstdlib>
#include <ctime>
int main(void)
{
    MaxHeap heap;
    int data[10];

    // 랜덤으로 데이터 생성
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        data[i] = rand() % 100;
    // 정렬 전 배열 값 출력
    printf("정렬 전: ");
    for (int i = 0; i < 10; i++)
        printf("%3d", data[i]);
    // 힙 정렬 실행
    heapSort(data, 10);
    // 정렬 후 배열 값 출력
    printf("\n정렬 후: ");
    for (int i = 0; i < 10; i++)
        printf("%3d", data[i]);
    printf("\n");

    return 0;
}