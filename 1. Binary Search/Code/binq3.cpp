#include <bits/stdc++.h>
using namespace std;
// find Pivot

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

int main()
{
    // int a[5] = {7,9,1,2,3};
    int a[5] = {3, 8, 10, 17, 1};
    cout << "Pivot is : " << findpivot(a, 5) << endl;
    return 0;
}