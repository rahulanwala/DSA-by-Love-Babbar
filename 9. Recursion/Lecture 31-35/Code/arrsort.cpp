#include <bits/stdc++.h>
using namespace std;

string arrsort(int a[], int n)
{
    if (n == 0 || n == 1)
    {
        return "YES";
    }

    string ans;
    if (a[1] < a[0])
        return "NO";
    else
    {
        ans = arrsort(a + 1, n - 1);
    }
    return ans;
}

int main()
{
    int arr[5] = {1, 2, 4, 5, 6};
    cout << arrsort(arr, 5) << endl;
    return 0;
}