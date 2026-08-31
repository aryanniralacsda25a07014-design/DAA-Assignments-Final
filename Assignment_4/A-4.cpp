// Aryan Nirala 25/DA/015
#include <iostream>
using namespace std;
// DFS function
void DFS(int vertex, int n, int graph[][100], bool visited[])
{
    visited[vertex] = true;
    cout << vertex << " ";

    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && !visited[i])
        {
            DFS(i, n, graph, visited);
        }
    }
}

int main()
{
    int n, edges;
    int graph[100][100] = {0};
    bool visited[100] = {false};

    cout << "Enter number of vertices: ";
    cin >> n;

    if (n <= 0 || n > 100)
    {
        cout << "Invalid number of vertices." << endl;
        return 0;
    }

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter the edges (u v):" << endl;

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        if (u >= 0 && u < n && v >= 0 && v < n)
        {
            // Undirected graph
            graph[u][v] = 1;
            graph[v][u] = 1;
        }
        else
        {
            cout << "Invalid edge. Vertices must be between 0 and "
                 << n - 1 << "." << endl;
            i--;
        }
    }

    cout << "\nConnected Components using DFS:" << endl;

    int component = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            component++;

            cout << "Component " << component << ": ";
            DFS(i, n, graph, visited);
            cout << endl;
        }
    }

    cout << "\nTotal Connected Components: " << component << endl;

    return 0;
}

