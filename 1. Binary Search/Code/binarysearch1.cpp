#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int a[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (a[mid] == key)
        {
            return mid;
        }
        if (a[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int main()
{
    int even[6] = {3, 5, 8, 10, 12, 23};
    int odd[5] = {4, 7, 9, 14, 21};

    int evenIndex = BinarySearch(even, 6, 12);
    cout << "Index of 12 is : " << evenIndex << endl;

    int oddIndex = BinarySearch(odd, 5, 9);
    cout << "Index of 12 is : " << oddIndex << endl;
    return 0;
}