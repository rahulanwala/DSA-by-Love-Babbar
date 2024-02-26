#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/guess-number-higher-or-lower-ii/

class Solution
{
    int rec(int start, int end)
    {
        if (start >= end)
        {
            return 0;
        }

        int maxi = INT_MAX;
        for (int i = start; i <= end; i++)
        {
            maxi = min(maxi, i + max(rec(start, i - 1), rec(i + 1, end)));
        }

        return maxi;
    }

    int mem(int start, int end, vector<vector<int>> &dp)
    {
        if (start >= end)
        {
            return 0;
        }

        if (dp[start][end] != -1)
        {
            return dp[start][end];
        }

        int maxi = INT_MAX;
        for (int i = start; i <= end; i++)
        {
            maxi = min(maxi, i + max(mem(start, i - 1, dp), mem(i + 1, end, dp)));
        }

        return dp[start][end] = maxi;
    }

    int tab(int n)
    {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int start = n; start >= 1; start--)
        {
            for (int end = start; end <= n; end++)
            {
                if (start == end)
                {
                    continue;
                }
                else
                {
                    int maxi = INT_MAX;
                    for (int i = start; i <= end; i++)
                    {
                        maxi = min(maxi, i + max(dp[start][i - 1], dp[i + 1][end]));
                    }

                    dp[start][end] = maxi;
                }
            }
        }

        return dp[1][n];
    }

public:
    int getMoneyAmount(int n)
    {
        // return rec(1,n);

        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        // return mem(1,n,dp);

        return tab(n);
    }
};

int main()
{

    return 0;
}