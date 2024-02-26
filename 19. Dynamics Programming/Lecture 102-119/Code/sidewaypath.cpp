#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-sideway-jumps/submissions/

class Solution
{
    int rec(vector<int> &obs, int lane, int pos)
    {
        if (pos >= obs.size() - 1)
        {
            return 0;
        }

        if (obs[pos + 1] != lane)
        {
            return rec(obs, lane, pos + 1);
        }
        else
        {
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++)
            {
                if (lane != i && obs[pos] != i)
                {
                    ans = min(ans, 1 + rec(obs, i, pos));
                }
            }
            return ans;
        }
    }

    int mem(vector<int> &obs, int lane, int pos, vector<vector<int>> &dp)
    {
        if (pos >= obs.size() - 1)
        {
            return 0;
        }

        if (dp[lane][pos] != -1)
        {
            return dp[lane][pos];
        }

        if (obs[pos + 1] != lane)
        {
            return mem(obs, lane, pos + 1, dp);
        }
        else
        {
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++)
            {
                if (lane != i && obs[pos] != i)
                {
                    ans = min(ans, 1 + mem(obs, i, pos, dp));
                }
            }
            dp[lane][pos] = ans;
            return dp[lane][pos];
        }
    }

    int tab(vector<int> &obs)
    {
        int n = obs.size() - 1;
        vector<vector<int>> dp(4, vector<int>(n + 1, 1e9));

        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for (int pos = n - 1; pos >= 0; pos--)
        {
            for (int lane = 1; lane <= 3; lane++)
            {
                if (obs[pos + 1] != lane)
                {
                    dp[lane][pos] = dp[lane][pos + 1];
                }
                else
                {
                    int ans = 1e9;
                    for (int i = 1; i <= 3; i++)
                    {
                        if (lane != i && obs[pos] != i)
                        {
                            ans = min(ans, 1 + dp[i][pos + 1]);
                        }
                    }
                    dp[lane][pos] = ans;
                }
            }
        }

        return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
    }

    int space(vector<int> &obs)
    {
        int n = obs.size() - 1;
        vector<int> curr(4, INT_MAX);
        vector<int> next(4, INT_MAX);

        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        for (int pos = n - 1; pos >= 0; pos--)
        {
            for (int lane = 1; lane <= 3; lane++)
            {
                if (obs[pos + 1] != lane)
                {
                    curr[lane] = next[lane];
                }
                else
                {
                    int ans = 1e9;
                    for (int i = 1; i <= 3; i++)
                    {
                        if (lane != i && obs[pos] != i)
                        {
                            ans = min(ans, 1 + next[i]);
                        }
                    }
                    curr[lane] = ans;
                }
            }
            next = curr;
        }

        return min(next[2], min(1 + next[1], 1 + next[3]));
    }

public:
    int minSideJumps(vector<int> &obstacles)
    {
        int currLane = 2;
        int currPos = 0;
        // return rec(obstacles,currLane,currPos);

        // vector<vector<int>>dp(4,vector<int>(obstacles.size(),-1));

        // return mem(obstacles,currLane,currPos,dp);

        // return tab(obstacles);

        return space(obstacles);
    }
};

int main()
{

    return 0;
}