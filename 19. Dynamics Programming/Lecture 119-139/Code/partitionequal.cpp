#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

class Solution
{
    int rec(int n, int arr[], int ind, int target)
    {
        if (target < 0 || ind >= n)
        {
            return 0;
        }

        if (target == 0)
        {
            return 1;
        }

        int inc = rec(n, arr, ind + 1, target - arr[ind]);

        int exc = rec(n, arr, ind + 1, target);

        if (inc == 1 || exc == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int mem(int n, int arr[], int ind, int target, vector<vector<int>> &dp)
    {
        if (target < 0 || ind >= n)
        {
            return 0;
        }

        if (target == 0)
        {
            return 1;
        }

        if (dp[ind][target] != -1)
        {
            return dp[ind][target];
        }

        int inc = mem(n, arr, ind + 1, target - arr[ind], dp);

        int exc = mem(n, arr, ind + 1, target, dp);

        if (inc == 1 || exc == 1)
        {
            return dp[ind][target] = 1;
        }
        else
        {
            return dp[ind][target] = 0;
        }
    }

    int tab(int n, int arr[], int t)
    {
        vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int target = 1; target <= t; target++)
            {
                int inc = 0;
                if (target - arr[ind] >= 0)
                {
                    inc = dp[ind + 1][target - arr[ind]];
                }

                int exc = dp[ind + 1][target];

                if (inc == 1 || exc == 1)
                {
                    dp[ind][target] = 1;
                }
                else
                {
                    dp[ind][target] = 0;
                }
            }
        }

        return dp[0][t];
    }

    int space(int n, int arr[], int t)
    {
        vector<int> curr(t + 1, 0);
        vector<int> next(t + 1, 0);

        curr[0] = 1;
        next[0] = 1;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int target = 1; target <= t; target++)
            {
                int inc = 0;
                if (target - arr[ind] >= 0)
                {
                    inc = next[target - arr[ind]];
                }

                int exc = next[target];

                if (inc == 1 || exc == 1)
                {
                    curr[target] = 1;
                }
                else
                {
                    curr[target] = 0;
                }
            }
            next = curr;
        }

        return next[t];
    }

public:
    int equalPartition(int N, int arr[])
    {
        int total = 0;

        for (int i = 0; i < N; i++)
        {
            total += arr[i];
        }

        if (total & 1)
        {
            return 0;
        }
        else
        {
            int target = total / 2;

            // return rec(N,arr,0,target);

            // vector<vector<int>>dp(N,vector<int>(target+1,-1));

            // return mem(N,arr,0,target,dp);

            // return tab(N,arr,target);

            return space(N, arr, target);
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
