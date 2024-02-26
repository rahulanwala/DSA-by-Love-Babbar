#include <bits/stdc++.h>
using namespace std;

int arrsum(int a[], int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return a[0];

    int sum = a[0] + arrsum(a + 1, n - 1);
    return sum;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    cout << "Sum of the array is = " << arrsum(arr, 5) << endl;
    return 0;
}