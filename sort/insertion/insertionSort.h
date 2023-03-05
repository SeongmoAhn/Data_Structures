// insertionSort.h
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j;
        for (j = i - 1; j >= 0 && arr[j] > key; j--)
            arr[j + 1] = arr[j]; // key값보다 큰 요소들을 한 칸씩 옮김
        arr[j + 1] = key;
    }
}