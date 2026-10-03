
#include <bits/stdc++.h>
using namespace std;

// Structure to represent an edge
struct Edge
{
    int u, v, wt;
};

// Comparator to sort edges by weight
bool compare(Edge a, Edge b)
{
    return a.wt < b.wt;
}

// Disjoint Set Union
class DSU
{
    vector<int> parent, rank;

public:

    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    // Find with path compression
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    // Union by rank
    void unite(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return;

        if (rank[pu] < rank[pv])
            parent[pu] = pv;

        else if (rank[pu] > rank[pv])
            parent[pv] = pu;

        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

void kruskals(int V, vector<Edge>& edges)
{
    // Sort edges by increasing weight
    sort(edges.begin(), edges.end(), compare);

    DSU dsu(V);

    int mstWeight = 0;
    int edgeCount = 0;

    cout << "\nEdges in MST:\n";

    for (auto e : edges)
    {
        int u = e.u;
        int v = e.v;
        int wt = e.wt;

        // Check whether adding edge forms a cycle
        if (dsu.find(u) != dsu.find(v))
        {
            dsu.unite(u, v);

            cout << u << " - " << v
                 << " : " << wt << endl;

            mstWeight += wt;
            edgeCount++;

            if (edgeCount == V - 1)
                break;
        }
    }

    if (edgeCount != V - 1)
    {
        cout << "MST does not exist. Graph is disconnected.\n";
        return;
    }

    cout << "Minimum Spanning Tree Weight: "
         << mstWeight << endl;
}

int main()
{
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges;

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < E; i++)
    {
        Edge e;
        cin >> e.u >> e.v >> e.wt;

        edges.push_back(e);
    }

    kruskals(V, edges);

    return 0;
}