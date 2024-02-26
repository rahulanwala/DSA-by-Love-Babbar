#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151?leftPanelTab=0

void dfs(int node, unordered_map<int, list<int>> adj, unordered_map<int, bool> &vis, stack<int> &st)
{
    vis[node] = true;

    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            dfs(nbr, adj, vis, st);
        }
    }
    st.push(node);
}

void revdfs(int node, unordered_map<int, list<int>> adj, unordered_map<int, bool> &vis)
{
    vis[node] = true;

    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            revdfs(nbr, adj, vis);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    { 
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    unordered_map<int, bool> vis;
    stack<int> st;

    // 1 -> topological sort
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, st);
        }
    }

    // 2 -> transpose graph
    unordered_map<int, list<int>> transpose;
    for (int i; i < v; i++)
    {
        vis[i] = false;
        for (auto nbr : adj[i])
        {
            transpose[nbr].push_back(i);
        }
    }

    // 3 -> count scc
    int count = 0;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();

        if (!vis[top])
        {
            count++;
            revdfs(top, transpose, vis);
        }
    }

    return count;
}

int main()
{

    return 0;
}