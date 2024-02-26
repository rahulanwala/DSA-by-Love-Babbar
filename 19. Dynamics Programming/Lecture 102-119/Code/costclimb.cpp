#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/min-cost-climbing-stairs/submissions/

class Solution
{
    int rec(vector<int> &cost, int n)
    {
        if (n == 0 || n == 1)
        {
            return cost[n];
        }

        int ans = cost[n] + min(rec(cost, n - 1), rec(cost, n - 2));

        return ans;
    }

    int recmem(vector<int> &cost, int n, vector<int> &dp)
    {
        if (n == 0 || n == 1)
        {
            return cost[n];
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }

        dp[n] = cost[n] + min(recmem(cost, n - 1, dp), recmem(cost, n - 2, dp));

        return dp[n];
    }

    int tab(vector<int> &cost, int n)
    {
        vector<int> dp(n + 1, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i <= n - 1; i++)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        return min(dp[n - 1], dp[n - 2]);
    }

    int opti(vector<int> &cost, int n)
    {
        int prev1 = cost[1];
        int prev2 = cost[0];

        for (int i = 2; i <= n - 1; i++)
        {
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();

        // int ans = min(rec(cost,n-1),rec(cost,n-2));

        vector<int> dp(n + 1, -1);
        // int ans = min(recmem(cost,n-1,dp),recmem(cost,n-2,dp));

        // int ans = tab(cost,n);

        int ans = opti(cost, n);

        return ans;
    }
};

int main()
{

    return 0;
}