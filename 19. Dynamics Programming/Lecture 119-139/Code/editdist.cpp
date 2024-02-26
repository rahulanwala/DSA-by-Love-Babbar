#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/edit-distance/

class Solution
{
    int rec(string &a, string &b, int i, int j)
    {
        if (i == a.size())
        {
            return b.size() - j;
        }

        if (j == b.size())
        {
            return a.size() - i;
        }

        int ans = 0;
        if (a[i] == b[j])
        {
            ans = rec(a, b, i + 1, j + 1);
        }
        else
        {
            int insert = 1 + rec(a, b, i, j + 1);
            int del = 1 + rec(a, b, i + 1, j);
            int replace = 1 + rec(a, b, i + 1, j + 1);
            ans = min(insert, min(del, replace));
        }

        return ans;
    }

    int mem(string &a, string &b, int i, int j, vector<vector<int>> &dp)
    {
        if (i == a.size())
        {
            return b.size() - j;
        }

        if (j == b.size())
        {
            return a.size() - i;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int ans = 0;
        if (a[i] == b[j])
        {
            ans = mem(a, b, i + 1, j + 1, dp);
        }
        else
        {
            int insert = 1 + mem(a, b, i, j + 1, dp);
            int del = 1 + mem(a, b, i + 1, j, dp);
            int replace = 1 + mem(a, b, i + 1, j + 1, dp);
            ans = min(insert, min(del, replace));
        }

        return dp[i][j] = ans;
    }

    int tab(string &a, string &b)
    {
        vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));

        for (int i = 0; i < a.size(); i++)
        {
            dp[i][b.size()] = a.size() - i;
        }

        for (int j = 0; j < b.size(); j++)
        {
            dp[a.size()][j] = b.size() - j;
        }

        for (int i = a.size() - 1; i >= 0; i--)
        {
            for (int j = b.size() - 1; j >= 0; j--)
            {
                int ans = 0;
                if (a[i] == b[j])
                {
                    ans = dp[i + 1][j + 1];
                }
                else
                {
                    int insert = 1 + dp[i][j + 1];
                    int del = 1 + dp[i + 1][j];
                    int replace = 1 + dp[i + 1][j + 1];
                    ans = min(insert, min(del, replace));
                }

                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }

    int space(string &a, string &b)
    {
        if (a.size() == 0)
        {
            return b.size();
        }

        if (b.size() == 0)
        {
            return a.size();
        }

        vector<int> curr(b.size() + 1, 0);
        vector<int> next(b.size() + 1, 0);

        for (int j = 0; j < b.size(); j++)
        {
            next[j] = b.size() - j;
        }

        for (int i = a.size() - 1; i >= 0; i--)
        {
            for (int j = b.size() - 1; j >= 0; j--)
            {
                // from base case
                curr[b.size()] = a.size() - i;

                int ans = 0;
                if (a[i] == b[j])
                {
                    ans = next[j + 1];
                }
                else
                {
                    int insert = 1 + curr[j + 1];
                    int del = 1 + next[j];
                    int replace = 1 + next[j + 1];
                    ans = min(insert, min(del, replace));
                }

                curr[j] = ans;
            }
            next = curr;
        }

        return next[0];
    }

public:
    int minDistance(string word1, string word2)
    {
        // return rec(word1,word2,0,0);

        // vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));

        // return mem(word1,word2,0,0,dp);

        // return tab(word1,word2);

        return space(word1, word2);
    }
};

int main()
{

    return 0;
}