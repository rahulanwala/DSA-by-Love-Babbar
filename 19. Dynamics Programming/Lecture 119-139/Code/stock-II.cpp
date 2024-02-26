#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution
{
    int rec(vector<int> &prices, int index, int buy)
    {
        if (index == prices.size())
        {
            return 0;
        }

        int profit = 0;
        if (buy == 1)
        {
            int buyKaro = -prices[index] + rec(prices, index + 1, 0);
            int skipKaro = rec(prices, index + 1, 1);
            profit = max(buyKaro, skipKaro);
        }
        else
        {
            int sellKaro = prices[index] + rec(prices, index + 1, 1);
            int skipKaro = rec(prices, index + 1, 0);
            profit = max(sellKaro, skipKaro);
        }
        return profit;
    }

    int mem(vector<int> &prices, int index, int buy, vector<vector<int>> &dp)
    {
        if (index == prices.size())
        {
            return 0;
        }

        if (dp[index][buy] != -1)
        {
            return dp[index][buy];
        }

        int profit = 0;
        if (buy == 1)
        {
            int buyKaro = -prices[index] + mem(prices, index + 1, 0, dp);
            int skipKaro = mem(prices, index + 1, 1, dp);
            profit = max(buyKaro, skipKaro);
        }
        else
        {
            int sellKaro = prices[index] + mem(prices, index + 1, 1, dp);
            int skipKaro = mem(prices, index + 1, 0, dp);
            profit = max(sellKaro, skipKaro);
        }

        return dp[index][buy] = profit;
    }

    int tab(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy == 1)
                {
                    int buyKaro = -prices[index] + dp[index + 1][0];
                    int skipKaro = dp[index + 1][1];
                    profit = max(buyKaro, skipKaro);
                }
                else
                {
                    int sellKaro = prices[index] + dp[index + 1][1];
                    int skipKaro = dp[index + 1][0];
                    profit = max(sellKaro, skipKaro);
                }

                dp[index][buy] = profit;
            }
        }

        return dp[0][1];
    }

    int space(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy == 1)
                {
                    int buyKaro = -prices[index] + next[0];
                    int skipKaro = next[1];
                    profit = max(buyKaro, skipKaro);
                }
                else
                {
                    int sellKaro = prices[index] + next[1];
                    int skipKaro = next[0];
                    profit = max(sellKaro, skipKaro);
                }

                curr[buy] = profit;
            }
            next = curr;
        }

        return next[1];
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        // return rec(prices,0,1);

        // vector<vector<int>>dp(n,vector<int>(2,-1));

        // return mem(prices,0,1,dp);

        return tab(prices);
    }
};

int main()
{

    return 0;
}