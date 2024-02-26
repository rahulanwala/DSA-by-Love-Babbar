#include <bits/stdc++.h>
using namespace std;

bool binsearch(int arr[], int s, int e, int k)
{
    if (s > e)
        return 0;

    int mid = s + (e - s) / 2;
    if (arr[mid] == k)
        return 1;

    if (arr[mid] < k)
        return binsearch(arr, mid + 1, e, k);
    else
        return binsearch(arr, s, mid - 1, k);
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int key = 3;

    if (binsearch(arr, 0, 4, key))
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;
    return 0;
}