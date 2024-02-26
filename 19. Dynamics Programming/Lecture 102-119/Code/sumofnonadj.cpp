#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=1

int rec(vector<int> &nums, int n)
{
    if (n < 0)
    {
        return 0;
    }

    if (n == 0)
    {
        return nums[0];
    }

    int inc = rec(nums, n - 2) + nums[n];
    int exc = rec(nums, n - 1);

    return max(inc, exc);
}

int recmem(vector<int> &nums, int n, vector<int> &dp)
{
    if (n < 0)
    {
        return 0;
    }

    if (n == 0)
    {
        return nums[0];
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int inc = recmem(nums, n - 2, dp) + nums[n];
    int exc = recmem(nums, n - 1, dp);
    dp[n] = max(inc, exc);

    return dp[n];
}

int tab(vector<int> &nums, int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = nums[0];

    for (int i = 1; i <= n; i++)
    {
        int inc = dp[i - 2] + nums[i];
        int exc = dp[i - 1];
        dp[i] = max(inc, exc);
    }

    return dp[n];
}

int spaceOpti(vector<int> &nums, int n)
{
    int prev2 = 0;
    int prev1 = nums[0];

    for (int i = 1; i <= n; i++)
    {
        int inc = prev2 + nums[i];
        int exc = prev1;
        prev2 = prev1;
        prev1 = max(inc, exc);
    }

    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    int n = nums.size();

    // return rec(nums,n-1);

    // vector<int>dp(n,-1);

    // return recmem(nums,n-1,dp);

    // return tab(nums,n-1);

    return spaceOpti(nums, n - 1);
}

int main()
{

    return 0;
}