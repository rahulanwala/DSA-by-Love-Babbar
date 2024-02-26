#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/library/articulation-points-in-a-graph

void dfs(int &timer, int node, unordered_map<int, list<int>> &adj, vector<int> &disc, vector<int> &low, int parent, unordered_map<int, bool> &vis, vector<vector<int>> &result, vector<bool> &ap)
{
    vis[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;
    for (auto nbr : adj[node])
    {
        if (nbr == parent)
        {
            continue;
        }

        if (!vis[nbr])
        {
            child++;
            dfs(timer, nbr, adj, disc, low, node, vis, result, ap);
            low[node] = min(low[node], low[nbr]);

            // check for bridge
            if ((low[nbr] >= disc[node]) && parent != -1)
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else
        {
            // back edge
            low[node] = min(low[node], disc[nbr]);
        }
    }

    // Case 1, if u is the root of the DFS tree and has more than one child.
    if (parent == -1 && child > 1)
    {
        ap[node] = true;
    }
}

void findArticulationPoints(unordered_map<int, list<int>> adj, int v, int e)
{
    // unordered_map<int, list<int>> adj;

    // for (int i = 0; i < e; i++)
    // {
    //     int u = edges[i][0];
    //     int v = edges[i][1];

    //     adj[u].push_back(v);
    //     adj[v].push_back(u);
    // }

    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    int parent = -1;
    unordered_map<int, bool> vis;
    vector<bool> ap;

    vector<vector<int>> result;
    int timer = 0;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(timer, i, adj, disc, low, parent, vis, result, ap);
        }
    }

    for (int i = 0; i < v; i++)
    {
        if (ap[i])
            cout << i << " ";
    }

    return;
}

int main()
{

    return 0;
}