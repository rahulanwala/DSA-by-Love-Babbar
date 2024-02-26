#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reducing-dishes/submissions/

class Solution
{
    int rec(vector<int> &sat, int ind, int time)
    {
        if (ind == sat.size())
        {
            return 0;
        }

        int inc = (sat[ind] * (time + 1)) + rec(sat, ind + 1, time + 1);

        int exc = rec(sat, ind + 1, time);

        // int ans = max(inc,exc);
        return max(inc, exc);
    }

    int mem(vector<int> &sat, int ind, int time, vector<vector<int>> &dp)
    {
        if (ind == sat.size())
        {
            return 0;
        }

        if (dp[ind][time] != -1)
        {
            return dp[ind][time];
        }

        int inc = (sat[ind] * (time + 1)) + mem(sat, ind + 1, time + 1, dp);

        int exc = mem(sat, ind + 1, time, dp);

        dp[ind][time] = max(inc, exc);
        return dp[ind][time];
    }

    int space(vector<int> &sat)
    {
        vector<int> curr(sat.size() + 1, 0);
        vector<int> next(sat.size() + 1, 0);

        for (int ind = sat.size() - 1; ind >= 0; ind--)
        {
            for (int time = ind; time >= 0; time--)
            {
                int inc = (sat[ind] * (time + 1)) + next[time + 1];

                int exc = next[time];

                curr[time] = max(inc, exc);
            }
            next = curr;
        }

        return next[0];
    }

public:
    int maxSatisfaction(vector<int> &sat)
    {
        sort(sat.begin(), sat.end());

        // return rec(sat,0,0);

        // vector<vector<int>>dp(sat.size(),vector<int>(sat.size(),-1));

        // return mem(sat,0,0,dp);

        // return tab(sat);

        return space(sat);
    }
};

int main()
{

    return 0;
}