// HeapSort.cpp
#include <queue>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;
void hSortDec(int a[], int n) // 최대힙을 이용한 내림차순 정렬
{
    priority_queue<int> maxH;
    for (int i = 0; i < n; i++)
        maxH.push(a[i]);
    for (int i = 0; i < n; i++)
    {
        a[i] = maxH.top();
        maxH.pop();
    }
}
void hSortInc(int a[], int n) // 최소힙을 이용한 오름차순 정렬
{
    priority_queue<int, vector<int>, greater<int> > minH;
    for (int i = 0; i < n; i++)
        minH.push(a[i]);
    for (int i = 0; i < n; i++)
    {
        a[i] = minH.top();
        minH.pop();
    }
}
int main(void)
{
    int data[10];
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        data[i] = rand() % 100;
    printf("정렬 전: ");
    for (int i = 0; i < 10; i++)
        printf("%3d", data[i]);
    printf("\n오름차순 정렬 후: ");
    hSortInc(data, 10);
    for (int i = 0; i < 10; i++)
        printf("%3d", data[i]);
    printf("\n내림차순 정렬 후: ");
    hSortDec(data, 10);
    for (int i = 0; i < 10; i++)
        printf("%3d", data[i]);
    printf("\n");

    return 0;
}