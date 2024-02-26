#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

bool isSafe(vector<vector<int>> &m, int n, int x, int y, vector<vector<int>> visited)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && (m[x][y] == 1) && (visited[x][y] == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(vector<vector<int>> &m, int n, int x, int y, vector<vector<int>> visited, string path, vector<string> &ans)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // 4 Movements --> LRUD

    // Left
    int newx = x;
    int newy = y - 1;
    if (isSafe(m, n, newx, newy, visited))
    {
        path.push_back('L');
        solve(m, n, newx, newy, visited, path, ans);
        path.pop_back();
    }

    // Right
    newx = x;
    newy = y + 1;
    if (isSafe(m, n, newx, newy, visited))
    {
        path.push_back('R');
        solve(m, n, newx, newy, visited, path, ans);
        path.pop_back();
    }

    // Up
    newx = x - 1;
    newy = y;
    if (isSafe(m, n, newx, newy, visited))
    {
        path.push_back('U');
        solve(m, n, newx, newy, visited, path, ans);
        path.pop_back();
    }

    // Down
    newx = x + 1;
    newy = y;
    if (isSafe(m, n, newx, newy, visited))
    {
        path.push_back('D');
        solve(m, n, newx, newy, visited, path, ans);
        path.pop_back();
    }

    visited[x][y] = 0;
}

int main()
{
    vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

    vector<vector<int>> visited = m;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            visited[i][j] = 0;
        }
    }

    vector<string> ans;
    string path = "";
    int x = 0;
    int y = 0;

    solve(m, 4, x, y, visited, path, ans);

    for (auto fa : ans)
    {
        cout << fa << endl;
    }
    cout << endl;
    return 0;
}