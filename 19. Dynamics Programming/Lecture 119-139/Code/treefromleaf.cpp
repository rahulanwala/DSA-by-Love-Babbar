#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

class Solution
{
    int rec(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right)
    {
        if (left == right)
        {
            return 0;
        }

        int ans = INT_MAX;
        for (int i = left; i < right; i++)
        {
            ans = min(ans, (maxi[{left, i}] * maxi[{i + 1, right}] + rec(arr, maxi, left, i) + rec(arr, maxi, i + 1, right)));
        }

        return ans;
    }

    int mem(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right, vector<vector<int>> &dp)
    {
        if (left == right)
        {
            return 0;
        }

        if (dp[left][right] != -1)
        {
            return dp[left][right];
        }

        int ans = INT_MAX;
        for (int i = left; i < right; i++)
        {
            ans = min(ans, (maxi[{left, i}] * maxi[{i + 1, right}] + mem(arr, maxi, left, i, dp) + mem(arr, maxi, i + 1, right, dp)));
        }

        return dp[left][right] = ans;
    }

    int tab(vector<int> &arr, map<pair<int, int>, int> &maxi)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int left = n - 1; left >= 0; left--)
        {
            for (int right = left; right < n; right++)
            {
                if (left == right)
                {
                    continue;
                }
                else
                {
                    int ans = INT_MAX;
                    for (int i = left; i < right; i++)
                    {
                        ans = min(ans, (maxi[{left, i}] * maxi[{i + 1, right}] + dp[left][i] + dp[i + 1][right]));
                    }

                    dp[left][right] = ans;
                }
            }
        }

        return dp[0][n - 1];
    }

public:
    int mctFromLeafValues(vector<int> &arr)
    {
        int n = arr.size();
        map<pair<int, int>, int> maxi;

        for (int i = 0; i < arr.size(); i++)
        {
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < arr.size(); j++)
            {
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
            }
        }

        // return rec(arr,maxi,0,arr.size()-1);

        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        // return mem(arr,maxi,0,arr.size()-1,dp);

        return tab(arr, maxi);
    }
};

int main()
{

    return 0;
}