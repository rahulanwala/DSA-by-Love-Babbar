#include <bits/stdc++.h>
using namespace std;

bool reclinear(int arr[], int n, int key)
{
    if (n == 0)
        return 0;

    if (arr[0] == key)
        return 1;
    else
    {
        bool ans = reclinear(arr + 1, n - 1, key);
        return ans;
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int key = 2;

    if (reclinear(arr, 5, key))
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;
    return 0;
}