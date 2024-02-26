#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/minimum-coins_2180776?leftPanelTab=0

int rec(int n, vector<int> days, vector<int> cost, int i)
{
    if (i >= n)
    {
        return 0;
    }

    // 1 day pass
    int op1 = cost[0] + rec(n, days, cost, i + 1);

    // 7-day pass
    int j;
    for (j = i; j < n && days[j] < days[i] + 7; j++)
        ;

    int op2 = cost[1] + rec(n, days, cost, j);

    // 30-day pass
    for (j = i; j < n && days[j] < days[i] + 30; j++)
        ;

    int op3 = cost[2] + rec(n, days, cost, j);

    int ans = min(op1, min(op2, op3));

    return ans;
}

int mem(int n, vector<int> days, vector<int> cost, int i, vector<int> &dp)
{
    if (i >= n)
    {
        return 0;
    }

    if (dp[i] != -1)
    {
        return dp[i];
    }

    // 1 day pass
    int op1 = cost[0] + mem(n, days, cost, i + 1, dp);

    // 7-day pass
    int j;
    for (j = i; j < n && days[j] < days[i] + 7; j++)
        ;

    int op2 = cost[1] + mem(n, days, cost, j, dp);

    // 30-day pass
    for (j = i; j < n && days[j] < days[i] + 30; j++)
        ;

    int op3 = cost[2] + mem(n, days, cost, j, dp);

    dp[i] = min(op1, min(op2, op3));

    return dp[i];
}

int tab(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n + 1, -1);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        // 1 day pass
        int op1 = cost[0] + dp[i + 1];

        // 7-day pass
        int j;
        for (j = i; j < n && days[j] < days[i] + 7; j++)
            ;

        int op2 = cost[1] + dp[j];

        // 30-day pass
        for (j = i; j < n && days[j] < days[i] + 30; j++)
            ;

        int op3 = cost[2] + dp[j];

        dp[i] = min(op1, min(op2, op3));
    }

    return dp[0];
}

int spaceOpti(int n, vector<int> days, vector<int> cost)
{
    queue<pair<int, int>> monthly;
    queue<pair<int, int>> weekly;

    int ans = 0;

    for (auto day : days)
    {
        // step-1 : remove expire days from queue
        while (!monthly.empty() && monthly.front().first + 30 <= day)
        {
            monthly.pop();
        }

        while (!weekly.empty() && weekly.front().first + 7 <= day)
        {
            weekly.pop();
        }

        // step-2 : push current days cost
        weekly.push({day, ans + cost[1]});
        monthly.push({day, ans + cost[2]});

        // step-3 : ans update
        ans = min(ans + cost[0], min(weekly.front().second, monthly.front().second));
    }

    return ans;
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.

    // return rec(n,days,cost,0);

    // vector<int>dp(n+1,-1);

    // return mem(n,days,cost,0,dp);

    // return tab(n,days,cost);\

    return spaceOpti(n, days, cost);
}

int main()
{

    return 0;
}