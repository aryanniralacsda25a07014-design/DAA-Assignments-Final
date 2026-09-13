#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int timer = 0;

void DFS(int u, int parent,
         vector<vector<int>>& adj,
         vector<bool>& visited,
         vector<int>& tin,
         vector<int>& low,
         vector<bool>& articulation)
{
    visited[u] = true;

    tin[u] = low[u] = timer++;

    int children = 0;

    for (int v : adj[u])
    {
        if (v == parent)
            continue;

        if (visited[v])
        {
            low[u] = min(low[u], tin[v]);
        }
        else
        {
            DFS(v, u, adj, visited, tin, low, articulation);

            low[u] = min(low[u], low[v]);

            if (parent != -1 && low[v] >= tin[u])
                articulation[u] = true;

            children++;
        }
    }

    if (parent == -1 && children > 1)
        articulation[u] = true;
}

int main()
{
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> adj(n + 1);

    cout << "Enter edges:\n";

    // IMPORTANT: e edges are read here
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    vector<int> tin(n + 1);
    vector<int> low(n + 1);
    vector<bool> articulation(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            DFS(i, -1, adj, visited, tin, low, articulation);
        }
    }

    cout << "\nArticulation Points (Cut Vertices): ";

    bool found = false;

    for (int i = 1; i <= n; i++)
    {
        if (articulation[i])
        {
            cout << i << " ";
            found = true;
        }
    }

    if (!found)
        cout << "None";

    cout << endl;

    return 0;
}