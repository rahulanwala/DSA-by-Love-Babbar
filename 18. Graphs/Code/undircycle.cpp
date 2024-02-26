#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1

// Using BFS --------->

bool isCycleBFS(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, int> &parent, int node)
{
    visited[node] = true;
    parent[node] = -1;
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto i : adj[front])
        {
            if (visited[i] && i != parent[front])
            {
                return true;
            }
            else if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
                parent[i] = front;
            }
        }
    }

    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // Write your code here.
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, int> parent;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (isCycleBFS(adj, visited, parent, i))
            {
                return "Yes";
            }
        }
    }
    return "No";
}

// using DFS -------->

bool isCycleDFS(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int parent, int node)
{
    visited[node] = true;

    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            bool isfound = isCycleDFS(adj, visited, node, i);
            if (isfound)
            {
                return true;
            }
        }
        else if (i != parent)
        {
            return true;
        }
    }

    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // Write your code here.
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, int> parent;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (isCycleDFS(adj, visited, -1, i))
            {
                return "Yes";
            }
        }
    }
    return "No";
}

int main()
{

    return 0;
}