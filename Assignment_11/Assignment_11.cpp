//Implementation of Dijkstra using cpp
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;   // {distance, node}

void dijkstra(int V, vector<vector<pii>>& adj, int src) {

    vector<int> dist(V, INT_MAX);

    // Min-heap: {distance, node}
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {

        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Ignore outdated entry
        if (d > dist[u])
            continue;

        for (auto edge : adj[u]) {

            int v = edge.first;
            int weight = edge.second;

            // Relaxation
            if (dist[u] + weight < dist[v]) {

                dist[v] = dist[u] + weight;

                pq.push({dist[v], v});
            }
        }
    }

    // Print shortest distances
    cout << "\nShortest distances from source " << src << ":\n";

    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << i << " : INF\n";
        else
            cout << i << " : " << dist[i] << endl;
    }
}

int main() {

    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pii>> adj(V);

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < E; i++) {

        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});   // Remove for directed graph
    }

    int src;

    cout << "Enter source vertex: ";
    cin >> src;

    dijkstra(V, adj, src);

    return 0;
}