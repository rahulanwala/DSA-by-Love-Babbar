#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int e)
{

    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainarrIndex = s;

    for (int i = 0; i < len1; i++)
        first[i] = arr[mainarrIndex++];

    mainarrIndex = mid + 1;

    for (int i = 0; i < len2; i++)
        second[i] = arr[mainarrIndex++];

    int index1 = 0;
    int index2 = 0;
    mainarrIndex = s;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
            arr[mainarrIndex++] = first[index1++];
        else
            arr[mainarrIndex++] = second[index2++];
    }

    while (index1 < len1)
        arr[mainarrIndex++] = first[index1++];

    while (index2 < len2)
        arr[mainarrIndex++] = second[index2++];

    delete []first;
    delete []second;
}

void mergesort(int arr[], int s, int e)
{

    if (s >= e)
        return;

    int mid = s + (e - s) / 2;

    // Left part sort kro
    mergesort(arr, s, mid);

    // Right part sort kro
    mergesort(arr, mid + 1, e);

    merge(arr, s, e);
}

int main()
{
    int arr[7] = {38, 27, 43, 3, 9, 82, 10};

    for (int i = 0; i < 7; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergesort(arr, 0, 6);
    for (int i = 0; i < 7; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}