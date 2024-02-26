#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/prim-s-mst_1095633?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i=0;i<g.size();i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }


    // 1 se start kr rhe to size = n+1
    vector<int>key(n+1);
    vector<bool>mst(n+1);
    vector<int>parent(n+1);

    for(int i=0;i<=n;i++){
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    // src = 1;
    key[1] = 0;
    parent[1] = -1;

    for(int i=1;i<n;i++){
        int mini = INT_MAX;
        int u;
        // find mini in key array
        for(int j=1;j<=n;j++){
            if(mst[j]==false && key[j]<mini){
                u = j;
                mini = key[j];
            }
        }

        // mark mst[u] true
        mst[u] = true;

        // check for adjacency list
        for(auto it:adj[u]){    
            int v = it.first;
            int w = it.second;

            if(mst[v]==false && key[v]>w){
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;

    for (int i = 2; i <= n; i++)
    {
        result.push_back(make_pair(make_pair(parent[i], i), key[i]));
    }

    return result;
}

int main()
{

    return 0;
}