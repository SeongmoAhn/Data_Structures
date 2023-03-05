// insertionSortFn.h
inline int ascend(int x, int y) { return y - x; } // 오름차순 비교함수
inline int descend(int x, int y) { return x - y; } // 내림차순 비교함수

void insertionSortFn(int arr[], int n, int (*f)(int, int))
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j;
        for (j = i - 1; j >= 0 && f(arr[j], key) < 0; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }
}