#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/peak-index-in-a-mountain-array/

int Peak(int a[], int n)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (a[mid] < a[mid + 1])
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

int main()
{
    int a[5] = {3, 4, 5, 2, 1};
    int pindex = Peak(a, 5);

    cout << "Peak index is : " << pindex << endl;
    return 0;
}