#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

bool isPossible(int a[], int n, int m, int mid)
{
    int stcount = 1;
    int page = 0;
    for (int i = 0; i < n; i++)
    {
        if (page + a[i] <= mid)
        {
            page += a[i];
        }
        else  
        {
            stcount++;
            if (stcount > m || a[i] > mid)
            {
                return false;
            }
            page = a[i];
        }
    } 
    return true;
}

int find(int a[], int n, int m)
{
    if (n < m)
    {
        return -1;
    }
    
    int s = 0;
    int ans = -1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    int e = sum;

    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (isPossible(a, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int a[4] = {10, 20, 30, 40};
    cout << "The answer is : " << find(a, 4, 2) << endl;
    return 0;
}