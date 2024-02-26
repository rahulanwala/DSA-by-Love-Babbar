#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution
{
    int rec(string &a, string &b, int i, int j)
    {
        if (i == a.size())
        {
            return 0;
        }

        if (j == b.size())
        {
            return 0;
        }

        if (a[i] == b[j])
        {
            return 1 + rec(a, b, i + 1, j + 1);
        }
        else
        {
            return max(rec(a, b, i + 1, j), rec(a, b, i, j + 1));
        }
    }

    int mem(string &a, string &b, int i, int j, vector<vector<int>> &dp)
    {
        if (i == a.size())
        {
            return 0;
        }

        if (j == b.size())
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (a[i] == b[j])
        {
            return dp[i][j] = 1 + mem(a, b, i + 1, j + 1, dp);
        }
        else
        {
            return dp[i][j] = max(mem(a, b, i + 1, j, dp), mem(a, b, i, j + 1, dp));
        }
    }

    int tab(string &a, string &b)
    {
        vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));

        for (int i = a.size() - 1; i >= 0; i--)
        {
            for (int j = b.size() - 1; j >= 0; j--)
            {
                if (a[i] == b[j])
                {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }

    int space(string &a, string &b)
    {
        vector<int> curr(b.size() + 1, 0);
        vector<int> next(b.size() + 1, 0);

        for (int i = a.size() - 1; i >= 0; i--)
        {
            for (int j = b.size() - 1; j >= 0; j--)
            {
                if (a[i] == b[j])
                {
                    curr[j] = 1 + next[j + 1];
                }
                else
                {
                    curr[j] = max(next[j], curr[j + 1]);
                }
            }
            next = curr;
        }

        return next[0];
    }

public:
    int longestPalindromeSubseq(string s)
    {
        reverse(s.begin(), s.end());
        string revs = s;

        reverse(s.begin(), s.end());

        // return rec(s,revs,0,0);

        // vector<vector<int>>dp(s.size(),vector<int>(revs.size(),-1));

        // return mem(s,revs,0,0,dp);

        // return tab(s,revs);

        return space(s, revs);
    }
};

int main()
{

    return 0;
}