#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1

class Solution
{
    int rec(int n, int m, vector<vector<int>> mat, int i, int j, int &maxi)
    {
        if (i >= n || j >= m)
        {
            return 0;
        }

        int right = rec(n, m, mat, i, j + 1, maxi);
        int diag = rec(n, m, mat, i + 1, j + 1, maxi);
        int down = rec(n, m, mat, i + 1, j, maxi);

        if (mat[i][j] == 1)
        {
            int ans = 1 + min(right, min(diag, down));
            maxi = max(maxi, ans);
            return ans;
        }
        else
        {
            return 0;
        }
    }

    int mem(int n, int m, vector<vector<int>> mat, int i, int j, int &maxi, vector<vector<int>> &dp)
    {
        if (i >= n || j >= m)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int right = mem(n, m, mat, i, j + 1, maxi, dp);
        int diag = mem(n, m, mat, i + 1, j + 1, maxi, dp);
        int down = mem(n, m, mat, i + 1, j, maxi, dp);

        if (mat[i][j] == 1)
        {
            dp[i][j] = 1 + min(right, min(diag, down));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }
        else
        {
            return dp[i][j] = 0;
        }
    }

    int tab(int n, int m, vector<vector<int>> mat, int &maxi)
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int right = dp[i][j + 1];
                int diag = dp[i + 1][j + 1];
                int down = dp[i + 1][j];

                if (mat[i][j] == 1)
                {
                    dp[i][j] = 1 + min(right, min(diag, down));
                    maxi = max(maxi, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }

        return dp[0][0];
    }

    int space(int n, int m, vector<vector<int>> mat, int &maxi)
    {
        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int right = curr[j + 1];
                int diag = next[j + 1];
                int down = next[j];

                if (mat[i][j] == 1)
                {
                    curr[j] = 1 + min(right, min(diag, down));
                    maxi = max(maxi, curr[j]);
                }
                else
                {
                    curr[j] = 0;
                }
            }
            next = curr;
        }

        return next[0];
    }

public:
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        // code here

        int maxi = 0;
        // rec(n,m,mat,0,0,maxi);

        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        // mem(n,m,mat,0,0,maxi,dp);

        // tab(n,m,mat,maxi);

        space(n, m, mat, maxi);

        return maxi;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}