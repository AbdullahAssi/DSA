#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

class Graph {
public:
    int V; // Number of vertices
    vector<vector<pair<int, int>>> adjList; // Adjacency list for weighted graph

    Graph(int vertices) : V(vertices), adjList(vertices) {}

    void addEdge(int u, int v, int w) {
        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w)); // For undirected graph
    }

    vector<int> dijkstra(int start) {
        vector<int> dist(V, INF); // Initialize distances to infinity
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap

        dist[start] = 0;
        pq.push(make_pair(0, start));

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (const auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                // Relaxation step
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        return dist;
    }
};

int main() {
    int vertices = 6;
    Graph graph(vertices);

    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 3);
    graph.addEdge(2, 4, 4);
    graph.addEdge(3, 4, 6);
    graph.addEdge(3, 5, 8);
    graph.addEdge(4, 5, 7);

    int startNode = 0;
    vector<int> shortestDistances = graph.dijkstra(startNode);

    cout << "Shortest distances from node " << startNode << " to all other nodes:" << endl;
    for (int i = 0; i < vertices; ++i) {
        cout << "Node " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}
