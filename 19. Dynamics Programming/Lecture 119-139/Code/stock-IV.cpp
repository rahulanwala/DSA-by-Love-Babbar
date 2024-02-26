#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution
{
    int rec(vector<int> &prices, int index, int openo, int k)
    {
        if (index == prices.size())
        {
            return 0;
        }

        if (openo == 2 * k)
        {
            return 0;
        }

        int profit = 0;
        if (openo % 2 == 0)
        {
            int buyKaro = -prices[index] + rec(prices, index + 1, openo + 1, k);
            int skipKaro = rec(prices, index + 1, openo, k);
            profit = max(buyKaro, skipKaro);
        }
        else
        {
            int sellKaro = prices[index] + rec(prices, index + 1, openo + 1, k);
            int skipKaro = rec(prices, index + 1, openo, k);
            profit = max(sellKaro, skipKaro);
        }

        return profit;
    }

    int mem(vector<int> &prices, int index, int openo, int k, vector<vector<int>> &dp)
    {
        if (index == prices.size())
        {
            return 0;
        }

        if (openo == 2 * k)
        {
            return 0;
        }

        if (dp[index][openo] != -1)
        {
            return dp[index][openo];
        }

        int profit = 0;
        if (openo % 2 == 0)
        {
            int buyKaro = -prices[index] + mem(prices, index + 1, openo + 1, k, dp);
            int skipKaro = mem(prices, index + 1, openo, k, dp);
            profit = max(buyKaro, skipKaro);
        }
        else
        {
            int sellKaro = prices[index] + mem(prices, index + 1, openo + 1, k, dp);
            int skipKaro = mem(prices, index + 1, openo, k, dp);
            profit = max(sellKaro, skipKaro);
        }

        return dp[index][openo] = profit;
    }

    int tab(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int openo = 2 * k - 1; openo >= 0; openo--)
            {
                int profit = 0;
                if (openo % 2 == 0)
                {
                    int buyKaro = -prices[index] + dp[index + 1][openo + 1];
                    int skipKaro = dp[index + 1][openo];
                    profit = max(buyKaro, skipKaro);
                }
                else
                {
                    int sellKaro = prices[index] + dp[index + 1][openo + 1];
                    int skipKaro = dp[index + 1][openo];
                    profit = max(sellKaro, skipKaro);
                }

                dp[index][openo] = profit;
            }
        }

        return dp[0][0];
    }

    int space(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<int> curr(2 * k + 1, 0);
        vector<int> next(2 * k + 1, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            for (int openo = 2 * k - 1; openo >= 0; openo--)
            {
                int profit = 0;
                if (openo % 2 == 0)
                {
                    int buyKaro = -prices[index] + next[openo + 1];
                    int skipKaro = next[openo];
                    profit = max(buyKaro, skipKaro);
                }
                else
                {
                    int sellKaro = prices[index] + next[openo + 1];
                    int skipKaro = next[openo];
                    profit = max(sellKaro, skipKaro);
                }

                curr[openo] = profit;
            }
            next = curr;
        }

        return next[0];
    }

public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();

        // return rec(prices,0,0,k);

        // vector<vector<int>>dp(n,vector<int>(2*k,-1));

        // return mem(prices,0,0,k,dp);

        // return tab(k,prices);

        return space(k, prices);
    }
};

int main()
{

    return 0;
}