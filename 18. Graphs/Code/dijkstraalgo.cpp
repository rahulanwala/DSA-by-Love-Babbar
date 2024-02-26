#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469?leftPanelTab=2

vector<int> dijkstra(vector<vector<int>> &vec, int ver, int edges, int src)
{
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> dist(ver);

    for (int i = 0; i < ver; i++)
    {
        dist[i] = INT_MAX;
    }

    set<pair<int, int>> st;

    dist[src] = 0;
    st.insert(make_pair(0, src));

    while (!st.empty())
    {
        auto top = *st.begin();

        int nodeDist = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        for (auto i : adj[topNode])
        {
            if (nodeDist + i.second < dist[i.first])
            {
                auto record = st.find(make_pair(dist[i.first], i.first));

                if (record != st.end())
                {
                    st.erase(record); 
                }

                dist[i.first] = nodeDist + i.second;
                st.insert(make_pair(dist[i.first], i.first));
            }
        }
    }

    return dist;
}

int main()
{

    return 0;
}