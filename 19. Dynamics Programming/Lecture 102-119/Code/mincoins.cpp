#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=1

int rec(vector<int> &num, int x)
{
    if (x == 0)
    {
        return 0;
    }

    if (x < 0)
    {
        return INT_MAX;
    }

    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans = rec(num, x - num[i]);

        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }

    return mini;
}

int recmem(vector<int> &num, int x, vector<int> &dp)
{
    if (x == 0)
    {
        return 0;
    }

    if (x < 0)
    {
        return INT_MAX;
    }

    if (dp[x] != -1)
    {
        return dp[x];
    }

    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans = recmem(num, x - num[i], dp);

        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }
    dp[x] = mini;

    return mini;
}

int tab(vector<int> &num, int x)
{
    int n = num.size();

    // Create a vector "dp" of size 'X'.
    vector<int> dp(x + 1, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i <= x; i++)
    {
        // Try out for each possible element and take the minimum.
        for (int j = 0; j < n; j++)
        {
            if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
        }
    }

    // Return -1 as it is not possible to make desired sum 'X'.
    if (dp[x] == INT_MAX)
    {
        return -1;
    }

    // Return the minimum number of elements.
    return dp[x];
}

int minimumElements(vector<int> &num, int x)
{
    // int ans = rec(num,x);

    vector<int> dp(x + 1, -1);
    int ans = recmem(num, x, dp);

    if (ans == INT_MAX)
    {
        return -1;
    }
    return ans;
}

int main()
{

    return 0;
}