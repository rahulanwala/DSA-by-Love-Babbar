#include <bits/stdc++.h>
using namespace std;
template <typename T>

class graph
{
public:
    unordered_map<T, list<T>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 -> undirected
        // direction = 1 -> directed

        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n, m;
    cout << "Enter number of nodes : " << endl;
    cin >> n;
    cout << "Enter number of edges : " << endl;
    cin >> m;

    graph<int> g;

    cout << "Enter the values of u and v : " << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // creating undirected graph
        g.addEdge(u, v, 0);
    }
    // 5 6 0 1 1 2 2 3 3 1 3 4 4 0

    g.printAdjList();

    return 0;
}