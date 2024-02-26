#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    int count = 0;

    for (int i = s+1; i <= e; i++)
    {
        if (arr[i] <= pivot)  
            count++;
    }

    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);

    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;
 
        if (i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }
    return pivotIndex;
}

void quicksort(int arr[], int s, int e)
{

    if (s >= e)
        return;

    int p = partition(arr, s, e);

    // Left part sort kro
    quicksort(arr, s, p - 1);

    // Right part sort kro
    quicksort(arr, p + 1, e);
}

int main()
{
    int arr[7] = {38, 27, 43, 3, 9, 82, 10};

    for (int i = 0; i < 7; i++)
        cout << arr[i] << " ";
    cout << endl;

    quicksort(arr, 0, 6);
    for (int i = 0; i < 7; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}