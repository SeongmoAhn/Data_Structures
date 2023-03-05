// selectionSort.h
inline void swap(int& x, int& y) // 매개변수로 레퍼런스형 사용, 포인터도 무방함
{
    int temp = x;
    x = y;
    y = temp;
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) // 마지막 요소는 자동으로 정렬되기에 n-1번 반복
    {
        int least = i;
        for (int j = i + 1; j < n; j++) // 배열 내 최소값 찾기
            if (arr[j] < arr[least])
                least = j;
        swap(arr[i], arr[least]);
    }
}