#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct Graph {
    int V;  // Number of vertices
    unordered_map<double, int> vertexIndexMap;  // Mapping double values to integer indices
    vector<vector<double>> adjList;
};

Graph* createGraph(int V) {
    Graph* graph = new Graph;
    graph->V = V;
    graph->adjList.resize(V);
    return graph;
}

void addEdge(Graph* graph, double src, double dest) {
    int srcIndex = graph->vertexIndexMap[src];
    graph->adjList[srcIndex].push_back(dest);
}

void BFS(Graph* graph, double startVertex) {
    int startVertexIndex = graph->vertexIndexMap[startVertex];

    bool* visited = new bool[graph->V];
    for (int i = 0; i < graph->V; i++) {
        visited[i] = false;
    }

    queue<int> q;
    visited[startVertexIndex] = true;
    q.push(startVertexIndex);

    while (!q.empty()) {
        int vertexIndex = q.front();
        q.pop();

        cout << graph->adjList[vertexIndex][0] << " ";

        for (auto adjVertex : graph->adjList[vertexIndex]) {
            if (!visited[graph->vertexIndexMap[adjVertex]]) {
                visited[graph->vertexIndexMap[adjVertex]] = true;
                q.push(graph->vertexIndexMap[adjVertex]);
            }
        }
    }
}

int main() {
    //graph with 7 vertices
    Graph* graph = createGraph(7);

    addEdge(graph, 1.29, 1.2);
    addEdge(graph, 1.2, 3.459);
    addEdge(graph, 1.2, 6.1);
    addEdge(graph, 6.1, 3.2);
    addEdge(graph, 3.459, 5.3);
    addEdge(graph, 3.2, 3.2);

    double startVertex = 3.2;

    cout << "BFS traversal starting from vertex " << startVertex << ": ";
    BFS(graph, graph->vertexIndexMap[startVertex]);

    return 0;
}

