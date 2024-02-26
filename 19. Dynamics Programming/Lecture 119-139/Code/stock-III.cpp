#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution
{
    int rec(vector<int> &prices, int index, int buy, int limit)
    {
        if (index == prices.size())
        {
            return 0;
        }

        if (limit == 0)
        {
            return 0;
        }

        int profit = 0;
        if (buy == 1)
        {
            int buyKaro = -prices[index] + rec(prices, index + 1, 0, limit);
            int skipKaro = rec(prices, index + 1, 1, limit);
            profit = max(buyKaro, skipKaro);
        }
        else
        {
            int sellKaro = prices[index] + rec(prices, index + 1, 1, limit - 1);
            int skipKaro = rec(prices, index + 1, 0, limit);
            profit = max(sellKaro, skipKaro);
        }

        return profit;
    }

    int mem(vector<int> &prices, int index, int buy, int limit, vector<vector<vector<int>>> &dp)
    {
        if (index == prices.size())
        {
            return 0;
        }

        if (limit == 0)
        {
            return 0;
        }

        if (dp[index][buy][limit] != -1)
        {
            return dp[index][buy][limit];
        }

        int profit = 0;
        if (buy == 1)
        {
            int buyKaro = -prices[index] + mem(prices, index + 1, 0, limit, dp);
            int skipKaro = mem(prices, index + 1, 1, limit, dp);
            profit = max(buyKaro, skipKaro);
        }
        else
        {
            int sellKaro = prices[index] + mem(prices, index + 1, 1, limit - 1, dp);
            int skipKaro = mem(prices, index + 1, 0, limit, dp);
            profit = max(sellKaro, skipKaro);
        }

        return dp[index][buy][limit] = profit;
    }

    int tab(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int limit = 1; limit <= 2; limit++)
                {
                    int profit = 0;
                    if (buy == 1)
                    {
                        int buyKaro = -prices[index] + dp[index + 1][0][limit];
                        int skipKaro = dp[index + 1][1][limit];
                        profit = max(buyKaro, skipKaro);
                    }
                    else
                    {
                        int sellKaro = prices[index] + dp[index + 1][1][limit - 1];
                        int skipKaro = dp[index + 1][0][limit];
                        profit = max(sellKaro, skipKaro);
                    }

                    dp[index][buy][limit] = profit;
                }
            }
        }

        return dp[0][1][2];
    }

    int space(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int limit = 1; limit <= 2; limit++)
                {
                    int profit = 0;
                    if (buy == 1)
                    {
                        int buyKaro = -prices[index] + next[0][limit];
                        int skipKaro = next[1][limit];
                        profit = max(buyKaro, skipKaro);
                    }
                    else
                    {
                        int sellKaro = prices[index] + next[1][limit - 1];
                        int skipKaro = next[0][limit];
                        profit = max(sellKaro, skipKaro);
                    }

                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }

        return next[1][2];
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        // return rec(prices,0,1,2);

        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));

        // return mem(prices,0,1,2,dp);

        // return tab(prices);

        return space(prices);
    }
};

int main()
{

    return 0;
}