//dijiksta with string
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
        adjMatrix[v][u] = w; // Assuming the graph is undirected
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
    // int E=8;


    Graph g(V);

    g.addEdge("Abdullah","ibtasam",2);
	g.addEdge("Abdullah","Moeez",4);
	g.addEdge("ibtasam","Zohaib",7);
	g.addEdge("ibtasam","Waleed",1);
	g.addEdge("Zohaib","Sultan",3);
	g.addEdge("Sultan","Mehdi",2);
	g.addEdge("Mehdi","Ziad",1);
	g.addEdge("Sultan","Ziad",5);


    string src="Abdullah";
    string dest="Ziad";

    g.dijkstra(src);
    g.printPath(dest);

    return 0;
}

