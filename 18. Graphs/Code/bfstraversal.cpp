#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1

void createAdj(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for (auto i : adjList[frontNode])
        {
            if (visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    unordered_map<int, set<int>> adjList;
    unordered_map<int, bool> visited;
    vector<int> ans;

    createAdj(adjList, edges);

    // for disconnected graph only
    for (int i = 0; i < vertex; i++)
    {
        if (visited[i] == 0)
        {
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;
}

int main()
{
    int vertex = 3;
    vector<pair<int, int>> edges = {{4, 4}, {0, 1}, {0, 3}, {1, 2}, {2, 3}};

    vector<int> ans = BFS(vertex, edges);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}