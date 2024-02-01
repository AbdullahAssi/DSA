#include<iostream>
#include<list>
using namespace std;

class Graph {
    int V;
    list<int> *adj; 

public:
    Graph(int V); 

    void addEdge(int v, int w); 

    void DFS(int v); 
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); 
}

void Graph::DFS(int v) {
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    list<int> stack;

    visited[v] = true;
    stack.push_back(v);

    while(!stack.empty()) {
        
        v = stack.back();
        cout << v << " ";
        stack.pop_back();

        for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!visited[*i]) {
                stack.push_back(*i);
                visited[*i] = true;
            }
        }
    }
}

int main() {
    Graph g(9); 

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 6);
    g.addEdge(3, 5);
    g.addEdge(3, 4);
    g.addEdge(4, 7);
    g.addEdge(6, 8);

    cout << "Depth First Traversal (starting from vertex 1): ";
    g.DFS(1);

    return 0;
}
