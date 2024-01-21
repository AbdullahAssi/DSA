//bidirectional graph

#include <iostream>
#include <queue>
#include <map>
#include <stack>

#define INF 99999

using namespace std;

class Graph {
    int V; // Number of vertices
    map<string, map<string, int> > adjMatrix; // Adjacency matrix: weights
    map<string, string> previous; // To keep track of the path

public:
    Graph(int vertices) : V(vertices) {}

    void addEdge(string u, string v, int w) {
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w;
    }

    void dijkstra(string src) {
        priority_queue<pair<int, string>, vector<pair<int, string> >,
greater<pair<int, string> > > pq;
        map<string, int> dist;

        for (auto const& pair : adjMatrix) {
            dist[pair.first] = INF;
        }

        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty()) {
            string u = pq.top().second;
            pq.pop();

            for (auto const& pair : adjMatrix[u]) {
                string v = pair.first;
                int weight = pair.second;

                if (weight > 0 && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                    previous[v] = u; // Keep track of the path
                }
            }
        }
    }

    void printPath(string destination) {
        stack<string> path;
        string vertex = destination;

        while (vertex != "") {
            path.push(vertex);
            vertex = previous[vertex];
        }

        cout << "Path: ";
        if (path.size() >= 2) {
            cout << path.top();
            path.pop();

            while (!path.empty()) {
                cout << " -> " << path.top();
                path.pop();
            }
        } else {
            cout << "No path found.";
        }

        cout << "\n";
    }

};

int main() {
    int V=6;
    int E=6;


    Graph g(V);

    g.addEdge("2.4","8.6",3);
	g.addEdge("3.9","2.4",1);
	g.addEdge("3.9","8.6",2);
	g.addEdge("8.6","6.3",9);
	g.addEdge("8.2","3.9",11);
	g.addEdge("3.9","3.85",1);


    string src="8.2";
    string dest="6.3";

    g.dijkstra(src);
    g.printPath(dest);

    return 0;
}
