#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/search-in-rotated-sorted-array_1082554?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTab=1

int findpivot(int a[], int n)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (a[mid] >= a[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return mid;
}

int BinarySearch(int a[], int s, int e, int key)
{
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

int findPosition(int a[], int n, int k)
{
    int p = findpivot(a, n);
    if (k >= a[p] && k <= a[n - 1])
    {
        return BinarySearch(a, p, n - 1, k);
    }
    else
    {
        return BinarySearch(a, 0, p - 1, k);
    }
}
int main()
{
    int a[5] = {7, 9, 1, 2, 3};
    int k = 9;
    cout << "Index of 9 is : " << findPosition(a, 5, k) << endl;
    return 0;
}