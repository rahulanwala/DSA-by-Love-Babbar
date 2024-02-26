#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/unique-binary-search-trees/

class Solution
{
    int rec(int n)
    {
        if (n <= 1)
        {
            return 1;
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += rec(i - 1) * rec(n - i);
        }

        return ans;
    }

    int mem(int n, vector<int> &dp)
    {
        if (n <= 1)
        {
            return 1;
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += mem(i - 1, dp) * mem(n - i, dp);
        }

        return dp[n] = ans;
    }

    int tab(int n)
    {
        vector<int> dp(n + 1, 0);

        dp[0] = dp[1] = 1;

        // i -> no. of nodes
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }

public:
    int numTrees(int n)
    {
        // return rec(n);

        // vector<int>dp(n+1,-1);

        // return mem(n,dp);

        return tab(n);
    }
};

int main()
{

    return 0;
}