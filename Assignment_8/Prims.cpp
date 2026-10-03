
#include <bits/stdc++.h>
using namespace std;

void prims(int V, vector<vector<pair<int,int>>>& adj)
{
    // Min heap: {weight, vertex}
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<int> visited(V, 0);

    int mstWeight = 0;

    // Start from vertex 0
    pq.push({0, 0});

    while (!pq.empty())
    {
        int wt = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Skip already visited vertices
        if (visited[u])
            continue;

        visited[u] = 1;

        mstWeight += wt;

        // Explore adjacent vertices
        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;

            if (!visited[v])
            {
                pq.push({weight, v});
            }
        }
    }

    cout << "Minimum Spanning Tree Weight: "
         << mstWeight << endl;
}

int main()
{
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    prims(V, adj);

    return 0;
}