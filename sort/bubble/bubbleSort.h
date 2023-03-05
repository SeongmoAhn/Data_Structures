// bubbleSort.h
inline void swap(int& x, int& y) // 매개변수로 레퍼런스형 사용, 포인터도 무방함
{
    int temp = x;
    x = y;
    y = temp;
}

void bubbleSort(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
    }
}