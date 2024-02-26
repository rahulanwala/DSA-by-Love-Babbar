#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/selection-sort_981162?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTab=1

int selectionsort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        swap(a[minIndex], a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

int main()
{
    int a[5] = {64, 25, 12, 22, 11};
    cout << "Sorted array is : ";
    selectionsort(a, 5);
    return 0;
}