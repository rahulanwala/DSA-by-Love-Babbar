#include <bits/stdc++.h>
using namespace std;

void movezero(int a[], int n)
{
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (a[j] != 0)
        {
            swap(a[i], a[j]);
            i++;
        }
    }
}

int main()
{
    int arr[6] = {0, 1, 0, 3, 12, 0};

    movezero(arr, 6);

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}