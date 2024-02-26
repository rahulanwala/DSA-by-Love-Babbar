#include <bits/stdc++.h>
using namespace std;

bool getbit(int n, int i)
{
    return (n & (1 << i)) != 0;
}

int setbit(int n, int i)
{
    return n | (1 << i);
}

int unique(int arr[], int n)
{
    int result = 0;
    for (int i = 0; i < 64; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (getbit(arr[j], i))
            {
                sum++;
            }
        }
        if (sum % 3 != 0)
        {
            result = setbit(result, i);
            cout<<result<<" "<<i<<endl;
        }
    }
    return result;
} 

int main()
{
    int arr[] = {1, 3, 2, 3, 4, 2, 1, 1, 3, 2};
    cout << unique(arr, 8) << endl;
    return 0;
}