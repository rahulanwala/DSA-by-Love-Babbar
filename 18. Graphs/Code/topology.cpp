#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h>

void dfs(unordered_map<int, list<int>> &adj, vector<bool> &visited, stack<int> &s, int node)
{
    visited[node] = true;

    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            dfs(adj, visited, s, i);
        }
    }

    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    unordered_map<int, list<int>> adj;
    vector<bool> visited;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    stack<int> s;
    vector<int> ans;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(adj, visited, s, i);
        }
    }

    while (!s.empty())
    {
        int a = s.top();
        ans.push_back(a);
        s.pop();
    }

    return ans;
}


// Kahn's Algorithm --------->

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    unordered_map<int, list<int>> adj;
    vector<int> indegree(v);

    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    } 

    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for (auto i : adj[front])
        {
            indegree[i]--;
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}