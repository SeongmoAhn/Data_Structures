// HuffmanCode.cpp
#include "MinHeap.h"
void MakeTree(int freq[], int n)
{
    MinHeap heap;
    for (int i = 0; i < n; i++)
        heap.insert(freq[i]);
    for (int i = 1; i < n; i++)
    {
        // 빈도수가 가장 작은 두 노드를 힙에서 제거
        HeapNode e1 = heap.remove();
        HeapNode e2 = heap.remove();
        // 제거한 두 노드의 값을 더해 다시 최소힙에 삽입
        heap.insert(e1.getKey() + e2.getKey());
        printf(" (%d + %d)\n", e1.getKey(), e2.getKey());
    }
}
int main(void)
{
    int freq[] = { 15, 12, 8, 6, 4 };
    MakeTree(freq, 5);

    return 0;
}