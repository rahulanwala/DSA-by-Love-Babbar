#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/painter-s-partition-problem_1089557

bool isPossible(int a[], int n, int m, int mid)
{
    int painter = 1;
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        if (time + a[i] <= mid)
        {
            time += a[i];
        }
        else
        { 
            painter += 1;
            if (painter > m || a[i] > mid)
            {
                return false;
            }
            time = a[i];
        }
    }
    return true; 
}

int find(int a[], int n, int m)
{
    int s = 0, ans = -1, sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    int e = sum;

    int mid = s + (e - s) / 2;

    while(s<=e){
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
    int a[4] = {5, 5, 5, 5};
    cout << "Answer is : " << find(a, 4, 2) << endl;
    return 0;
}