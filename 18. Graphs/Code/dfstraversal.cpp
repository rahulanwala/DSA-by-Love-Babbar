#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462?leftPanelTab=1

void dfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &comp, int node)
{
    visited[node] = true;

    comp.push_back(node);

    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            dfs(adj, visited, comp, i);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> comp;
            dfs(adj, visited, comp, i);
            ans.push_back(comp);
        }
    }

    return ans;
}

int main()
{
    int vertex = 3;
    vector<vector<int>> edges = {{4, 4}, {0, 1}, {0, 3}, {1, 2}, {2, 3}};

    vector<vector<int>> ans = depthFirstSearch(vertex,edges.size(), edges);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}