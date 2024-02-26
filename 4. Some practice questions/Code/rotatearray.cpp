#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int>& arr, int n, int k)
{
    vector<int> temp(n);

    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = arr[i];
    }
 
    arr = temp;
}

int main()
{
    vector<int> arr = {11, 12, 13, 14, 15};

    int k = 3;

    rotate(arr, 5, k);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}