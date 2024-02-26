#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/wildcard-matching/

class Solution
{
    bool rec(string &s, string &p, int i, int j)
    {
        if (i < 0 && j < 0)
        {
            return true;
        }

        if (i >= 0 && j < 0)
        {
            return false;
        }

        if (i < 0 && j >= 0)
        {
            for (int k = 0; k <= j; k++)
            {
                if (p[k] != '*')
                {
                    return false;
                }
            }
            return true;
        }

        if (s[i] == p[j] || p[j] == '?')
        {
            return rec(s, p, i - 1, j - 1);
        }
        else if (p[j] == '*')
        {
            return (rec(s, p, i, j - 1) | rec(s, p, i - 1, j));
        }
        else
        {
            return false;
        }
    }

    bool mem(string &s, string &p, int i, int j, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
        {
            return true;
        }

        if (i > 0 && j == 0)
        {
            return false;
        }

        if (i == 0 && j > 0)
        {
            for (int k = 1; k <= j; k++)
            {
                if (p[k - 1] != '*')
                {
                    return false;
                }
            }
            return true;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
        {
            return dp[i][j] = mem(s, p, i - 1, j - 1, dp);
        }
        else if (p[j - 1] == '*')
        {
            return dp[i][j] = (mem(s, p, i, j - 1, dp) | mem(s, p, i - 1, j, dp));
        }
        else
        {
            return dp[i][j] = false;
        }
    }

    bool tab(string &s, string &p)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, 0));

        dp[0][0] = true;

        for (int j = 1; j <= p.size(); j++)
        {
            bool flag = true;
            for (int k = 1; k <= j; k++)
            {
                if (p[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= p.size(); j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    dp[i][j] = (dp[i][j - 1] | dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }

        return dp[s.size()][p.size()];
    }

    bool space(string &s, string &p)
    {
        vector<int> prev(p.size() + 1, 0);
        vector<int> curr(p.size() + 1, 0);

        prev[0] = true;

        for (int j = 1; j <= p.size(); j++)
        {
            bool flag = true;
            for (int k = 1; k <= j; k++)
            {
                if (p[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= p.size(); j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                {
                    curr[j] = prev[j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    curr[j] = (curr[j - 1] | prev[j]);
                }
                else
                {
                    curr[j] = false;
                }
            }
            prev = curr;
        }

        return prev[p.size()];
    }

public:
    bool isMatch(string s, string p)
    {
        // return rec(s,p,s.size()-1,p.size()-1);

        // 1 based indexing
        // vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));

        // return mem(s,p,s.size(),p.size(),dp);

        // return tab(s,p);

        return space(s, p);
    }
};

int main()
{

    return 0;
}