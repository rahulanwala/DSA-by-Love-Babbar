#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/number-of-ways_3755252?leftPanelTab=1

int rec(vector<int> &num, int tar)
{
    if (tar < 0)
    {
        return 0;
    }

    if (tar == 0)
    {
        return 1;
    }

    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans += rec(num, tar - num[i]);
    }

    return ans;
}

int mem(vector<int> &num, int tar, vector<int> &dp)
{
    if (tar < 0)
    {
        return 0;
    }

    if (tar == 0)
    {
        return 1;
    }

    if (dp[tar] != -1)
    {
        return dp[tar];
    }

    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans += mem(num, tar - num[i], dp);
    }

    dp[tar] = ans;

    return dp[tar];
}

int tab(vector<int> &num, int tar)
{
    vector<int> dp(tar + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= tar; i++)
    {
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0)
            {
                dp[i] += dp[i - num[j]];
            }
        }
    }

    return dp[tar];
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.

    // return rec(num,tar);

    vector<int> dp(tar + 1, -1);

    return mem(num, tar, dp);

    // return tab(num,tar);
}

int main()
{

    return 0;
}