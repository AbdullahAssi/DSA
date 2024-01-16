#include <iostream>
#include <queue>

#define INF 99999
#define MAX_VERTICES 100

using namespace std;

class Graph {
    int V; // Number of vertices
    int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix: weights

public:
    Graph(int vertices) : V(vertices) {
        for (int i = 0; i < MAX_VERTICES; ++i) {
            for (int j = 0; j < MAX_VERTICES; ++j) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v, int w) {
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w; // Assuming the graph is undirected
    }

    void dijkstra(int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int dist[MAX_VERTICES];

        for (int i = 0; i < MAX_VERTICES; ++i) {
            dist[i] = INF;
        }

        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (int v = 0; v < V; ++v) {
                int weight = adjMatrix[u][v];

                if (weight > 0 && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Print the shortest distances
        cout << "Vertex \t Distance from Source\n";
        for (int i = 1; i <= V; ++i)
            cout << i << "\t\t" << dist[i] << "\n";
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);
    g.addEdge(1,2,10);
    g.addEdge(1,3,5);
    g.addEdge(1,4,3);
    g.addEdge(2,6,2);
    g.addEdge(3,4,3);
    g.addEdge(4,5,8);
    g.addEdge(5,6,6);
    g.addEdge(6,3,9);

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    g.dijkstra(src);

    return 0;
}