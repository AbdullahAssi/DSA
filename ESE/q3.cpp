#include<iostream>
using namespace std;

class Graph {
private:
    bool** adjMatrix;
    int numVtx;

public:
    Graph(int numVtx) {
        this->numVtx = numVtx;
        adjMatrix = new bool*[numVtx];
        for (int i = 0; i < numVtx; i++) {
            adjMatrix[i] = new bool[numVtx];
            for (int j = 0; j < numVtx; j++) {
                adjMatrix[i][j] = false;
            }
        }
    }

    void addEdge(int i, int j) {
        adjMatrix[i][j] = true;
        adjMatrix[j][i] = true;
    }

    void deleteEdge(int i, int j) {
        adjMatrix[i][j] = false;
        adjMatrix[j][i] = false;
    }

    void toString() {
        for (int i = 0; i < numVtx; i++) {
            cout << i << " : ";
            for (int j = 0; j < numVtx; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~Graph() {
        for (int i = 0; i < numVtx; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
};

int main() {
    Graph g(7);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(1, 4);
    g.addEdge(1, 5);
    g.addEdge(1, 6);
    g.addEdge(2, 0);
    g.addEdge(2, 4);
    g.addEdge(3, 0);
    g.addEdge(3, 5);
    g.addEdge(3, 6);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(4, 2);
    g.addEdge(4, 6);
    g.addEdge(5, 1);
    g.addEdge(5, 3);
    g.addEdge(5, 6);
    g.addEdge(6, 1);
    g.addEdge(6, 3);
    g.addEdge(6, 4);
    g.addEdge(6, 5);
    g.toString();
    return 0;
}