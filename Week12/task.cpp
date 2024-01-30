#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    vector<vector<int>> adjacencyMatrix;

public:
    Graph(int numVertices) {
        adjacencyMatrix.resize(numVertices, vector<int>(numVertices, 0));
    }

    void insertVertex() {
        int numVertices = adjacencyMatrix.size();
        for (int i = 0; i < numVertices; i++) {
            adjacencyMatrix[i].push_back(0);
        }
        adjacencyMatrix.push_back(vector<int>(numVertices + 1, 0));
    }


    void deleteVertex(int vertex) {
        int numVertices = adjacencyMatrix.size();
        if (vertex < 0 || vertex >= numVertices) {
            throw invalid_argument("Invalid vertex!");
        }

        adjacencyMatrix.erase(adjacencyMatrix.begin() + vertex);
        for (int i = 0; i < numVertices - 1; i++) {
            adjacencyMatrix[i].erase(adjacencyMatrix[i].begin() + vertex);
        }
    }

    void insertEdge(int vertex1, int vertex2) {
        int numVertices = adjacencyMatrix.size();
        if (vertex1 < 0 || vertex1 >= numVertices || vertex2 < 0 || vertex2 >= numVertices) {
            throw invalid_argument("Invalid vertices!");
        }

        adjacencyMatrix[vertex1][vertex2] = 1;
        adjacencyMatrix[vertex2][vertex1] = 1;
    }

    void deleteEdge(int vertex1, int vertex2) {
        int numVertices = adjacencyMatrix.size();
        if (vertex1 < 0 || vertex1 >= numVertices || vertex2 < 0 || vertex2 >= numVertices) {
            throw invalid_argument("Invalid vertices!");
        }

        adjacencyMatrix[vertex1][vertex2] = 0;
        adjacencyMatrix[vertex2][vertex1] = 0;
    }

    void printGraph() {
        for (int i = 0; i < adjacencyMatrix.size(); i++) {
            cout<<"Vertex "<<i<<": ";
            for (int j = 0; j < adjacencyMatrix[i].size(); j++) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph(5);

    // Print the initial graph
    cout << "Graph initially: \n";
    graph.printGraph();

    try {
        graph.insertEdge(2, 1);
        cout << "Graph after inserting an edge between vertex 2 and vertex 1: \n";
        graph.printGraph();
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }


    // Insert a new vertex
    graph.insertVertex();
    cout << "Graph after inserting a new vertex: \n";
    graph.printGraph();


    // Delete vertex 2
    try {
        graph.deleteVertex(2);
        cout << "Graph after deleting vertex 2: \n";
        graph.printGraph();
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    // Insert an edge between vertex 1 and vertex 3
    try {
        graph.insertEdge(1, 3);
        cout << "Graph after inserting an edge between vertex 1 and vertex 3: \n";
        graph.printGraph();
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    try {
        graph.insertEdge(0, 4);
        cout << "Graph after inserting an edge between vertex 0 and vertex 4: \n";
        graph.printGraph();
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }


    // Delete the edge between vertex 0 and vertex 4
    try {
        graph.deleteEdge(0, 4);
        cout << "Graph after deleting an edge between vertex 0 and vertex 4: \n";
        graph.printGraph();
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
