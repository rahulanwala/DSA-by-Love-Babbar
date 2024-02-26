#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/submissions/

class Solution
{
    bool check(vector<int> &a, vector<int> &b)
    {
        if (a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2])
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int rec(int n, vector<vector<int>> &cuboids, int curr, int prev)
    {
        if (curr == n)
        {
            return 0;
        }

        // include
        int inc = 0;
        if (prev == -1 || check(cuboids[prev], cuboids[curr]))
        {
            inc = cuboids[curr][2] + rec(n, cuboids, curr + 1, curr);
        }

        // exclude
        int exc = rec(n, cuboids, curr + 1, prev);

        return max(inc, exc);
    }

    int mem(int n, vector<vector<int>> &cuboids, int curr, int prev, vector<vector<int>> &dp)
    {
        if (curr == n)
        {
            return 0;
        }

        if (dp[curr][prev + 1] != -1)
        {
            return dp[curr][prev + 1];
        }

        // include
        int inc = 0;
        if (prev == -1 || check(cuboids[prev], cuboids[curr]))
        {
            inc = cuboids[curr][2] + mem(n, cuboids, curr + 1, curr, dp);
        }

        // exclude
        int exc = mem(n, cuboids, curr + 1, prev, dp);

        dp[curr][prev + 1] = max(inc, exc);

        return dp[curr][prev + 1];
    }

    int tab(int n, vector<vector<int>> &cuboids)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int inc = 0;
                if (prev == -1 || check(cuboids[prev], cuboids[curr]))
                {
                    inc = cuboids[curr][2] + dp[curr + 1][curr + 1];
                }

                // exclude
                int exc = dp[curr + 1][prev + 1];

                dp[curr][prev + 1] = max(inc, exc);
            }
        }

        return dp[0][0];
    }

    int space(vector<vector<int>> &cuboids)
    {
        int n = cuboids.size();
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i - 1; j >= -1; j--)
            {
                int inc = 0;
                if (j == -1 || check(cuboids[j], cuboids[i]))
                {
                    inc = cuboids[i][2] + next[i + 1];
                }

                int exc = next[j + 1];

                curr[j + 1] = max(inc, exc);
            }
            next = curr;
        }

        return next[0];
    }

public:
    int maxHeight(vector<vector<int>> &cuboids)
    {
        for (int i = 0; i < cuboids.size(); i++)
        {
            sort(cuboids[i].begin(), cuboids[i].end());
        }

        sort(cuboids.begin(), cuboids.end());

        int n = cuboids.size();

        // return rec(n,cuboids,0,-1);

        // vector<vector<int>>dp(n,vector<int>(n+1,-1));

        // return mem(n,cuboids,0,-1,dp);

        // return tab(n,cuboids);

        return space(cuboids);
    }
};

int main()
{

    return 0;
}