//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    int rec(int n)
    {
        if (n == 0)
        {
            return 0;
        }

        int ans = n; // at max can reach n
        for (int i = 1; i * i <= n; i++)
        {
            ans = min(ans, 1 + rec(n - i * i));
        }

        return ans;
    }

    int mem(int n, vector<int> &dp)
    {
        if (n == 0)
        {
            return 0;
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }

        int ans = n; // at max can reach n
        for (int i = 1; i * i <= n; i++)
        {
            ans = min(ans, 1 + mem(n - i * i, dp));
        }

        dp[n] = ans;

        return dp[n];
    }

    int tab(int n)
    {
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= n; j++)
            {
                if (i - j * j >= 0)
                {
                    dp[i] = min(dp[i], 1 + dp[i - j * j]);
                }
            }
        }

        return dp[n];
    }

public:
    int MinSquares(int n)
    {
        // Code here

        // return rec(n);

        // vector<int>dp(n+1,-1);

        // return mem(n,dp);

        return tab(n);
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.MinSquares(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends