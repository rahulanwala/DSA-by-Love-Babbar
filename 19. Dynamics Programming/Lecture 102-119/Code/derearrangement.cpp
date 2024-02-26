#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/count-derangements_873861?leftPanelTab=1

#define m 1000000007

long long rec(int n)
{
    if (n == 1)
    {
        return 0;
    }

    if (n == 2)
    {
        return 1;
    }

    int ans = (((n - 1) % m) * (((rec(n - 1)) % m) + ((rec(n - 2)) % m)) % m) % m;

    return ans;
}

long long mem(int n, vector<int> &dp)
{
    if (n == 1)
    {
        return 0;
    }

    if (n == 2)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = (((n - 1) % m) * (((mem(n - 1, dp)) % m) + ((mem(n - 2, dp)) % m)) % m) % m;

    return dp[n];
}

long long tab(int n)
{
    vector<long long> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        long long first = dp[i - 1] % m;
        long long second = dp[i - 2] % m;
        long long sum = (first + second) % m;

        int ans = (((i - 1) % m) * (sum)) % m;

        dp[i] = ans;
    }

    return dp[n];
}

long long spaceOpti(int n)
{
    long long prev2 = 0;
    long long prev1 = 1;

    for (int i = 3; i <= n; i++)
    {
        long long ans = (((i - 1) % m) * (((prev1 % m) + (prev2 % m)) % m)) % m;
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

long long int countDerangements(int n)
{
    // Write your code here.

    // return rec(n);

    // vector<int>dp(n+1,-1);

    // return mem(n,dp);

    // return tab(n);

    return spaceOpti(n);
}

int main()
{

    return 0;
}