#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/ninja-and-the-fence_3210208?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

#define m 1000000007

int add(int a, int b)
{
    return ((a % m + b % m) % m);
}

int mul(int a, int b)
{
    return ((a % m) * 1LL * (b % m)) % m;
}

int rec(int n, int k)
{
    if (n == 1)
    {
        return k;
    }

    if (n == 2)
    {
        return add(k, mul(k, k - 1));
        // return k*k;
    }

    int ans = add(mul(rec(n - 2, k), k - 1), mul(rec(n - 1, k), k - 1));

    // int ans = (rec(n-1,k)*(k-1)) + (rec(n-2,k)*(k-1));

    return ans;
}

int mem(int n, int k, vector<int> &dp)
{
    if (n == 1)
    {
        return k;
    }

    if (n == 2)
    {
        return add(k, mul(k, k - 1));
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = add(mul(mem(n - 2, k, dp), k - 1), mul(mem(n - 1, k, dp), k - 1));

    return dp[n];
}

int tab(int n, int k)
{
    vector<int> dp(n + 1, -1);
    dp[1] = k;
    dp[2] = add(k, mul(k, k - 1));

    for (int i = 3; i <= n; i++)
    {
        dp[i] = add(mul(dp[i - 1], k - 1), mul(dp[i - 2], k - 1));
    }

    return dp[n];
}

int spaceOpti(int n, int k)
{
    int prev2 = k;
    int prev1 = add(k, mul(k, k - 1));

    for (int i = 3; i <= n; i++)
    {
        int ans = add(mul(prev1, k - 1), mul(prev2, k - 1));
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int numberOfWays(int n, int k)
{
    // Write your code here.

    // return rec(n,k);

    // vector<int>dp(n+1,-1);

    // return mem(n,k,dp);

    // return tab(n,k);

    return spaceOpti(n, k);
}

int main()
{

    return 0;
}
