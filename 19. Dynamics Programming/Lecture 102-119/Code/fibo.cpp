#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/nth-fibonacci-number_74156?leftPanelTab=1

int rec(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    return rec(n - 1) + rec(n - 2);
}

int recmem(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = recmem(n - 1, dp) + recmem(n - 2, dp);

    return dp[n];
}

int tab(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int opti(int n)
{
    int prev1 = 1;
    int prev2 = 0;

    if (n == 0)
    {
        return prev2;
    }

    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    int n;
    cin >> n;
    cout << rec(n) << endl;

    vector<int> dp(n + 1, -1);
    cout << recmem(n, dp) << endl;

    cout << tab(n) << endl;

    cout << opti(n) << endl;
}