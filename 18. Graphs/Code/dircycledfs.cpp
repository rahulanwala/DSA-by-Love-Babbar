#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=1

bool isCycle(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited, int node)
{
    visited[node] = true;
    dfsvisited[node] = true;

    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            bool ispresent = isCycle(adj, visited, dfsvisited, i);
            if (ispresent)
            {
                return true;
            }
        }
        else if (dfsvisited[i])
        {
            return true;
        }
    }
    dfsvisited[node] = false;

    return false;
}

bool detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // Write your code here.
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsvisited;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (isCycle(adj, visited, dfsvisited, i))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{

    return 0;
}