#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/rat-in-a-maze_1215030?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

bool isSafe(int newx, int newy, vector<vector<int>> &arr, int n, vector<vector<bool>> visited)
{
    if ((newx >= 0 && newx < n && newy >= 0 && newy < n) && (arr[newx][newy] == 1) && (visited[newx][newy] != 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<vector<bool>> visited, vector<string> &ans, string path)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return; 
    }

    // Down
    if (isSafe(x + 1, y, arr, n, visited))
    {
        visited[x][y] = 1;
        solve(x + 1, y, arr, n, visited, ans, path + 'D');
    }

    // Left
    if (isSafe(x, y - 1, arr, n, visited))
    {
        visited[x][y] = 1;
        solve(x, y - 1, arr, n, visited, ans, path + 'L');
    }

    // Right
    if (isSafe(x, y + 1, arr, n, visited))
    {
        visited[x][y] = 1;
        solve(x, y + 1, arr, n, visited, ans, path + 'R');
    }

    // Up
    if (isSafe(x - 1, y, arr, n, visited))
    {
        visited[x][y] = 1;
        solve(x - 1, y, arr, n, visited, ans, path + 'U');
    }

    visited[x][y] = 0;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    string path = "";

    if (arr[0][0] == 0)
    {
        return ans;
    }

    solve(0, 0, arr, n, visited, ans, path);

    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 0, 0, 0}, {1, 1, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    int n = 3;

    vector<string> ans = searchMaze(arr, n);

    for (auto i : ans)
    {
        cout << i << endl;
    }

    return 0;
}