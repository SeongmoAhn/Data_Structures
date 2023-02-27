// HeapSort.h
#include "MaxHeap.h"
void heapSort(int a[], int n)
{
    MaxHeap h;
    // 배열의 모든 요소를 힙에 삽입
    for (int i = 0; i < n; i++)
        h.insert(a[i]);
    
    // 맥스 힙을 사용했으므로 오름차순으로 정렬하기 위해
    // 배열의 뒤부터 요소들을 채움
    for (int i = n - 1; i >= 0; i--)
        a[i] = h.remove().getKey();
}