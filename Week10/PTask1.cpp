#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <limits>

// Node struct representing a graph node with weight
struct GraphNode {
    double node;
    double weight;

    GraphNode(double n, double w) : node(n), weight(w) {}
};

class Graph {
private:
    std::unordered_map<double, std::list<std::pair<double, double>>> adjacencyList;

public:
    void addEdge(double src, double dest, double weight) {
        adjacencyList[src].push_back(std::make_pair(dest, weight));
        adjacencyList[dest].push_back(std::make_pair(src, weight));
    }

    // Weighted Breadth First Search function
    void BFS(double startNode) {
        std::unordered_set<double> visited;
        std::queue<GraphNode> bfsQueue;

        visited.insert(startNode);
        bfsQueue.push(GraphNode(startNode, 0.0));

        while (!bfsQueue.empty()) {
            GraphNode current = bfsQueue.front();
            std::cout << "Node: " << current.node << " | Weight: " << current.weight << std::endl;
            bfsQueue.pop();

            for (const auto &neighborPair : adjacencyList[current.node]) {
                double neighbor = neighborPair.first;
                double edgeWeight = neighborPair.second;

                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    bfsQueue.push(GraphNode(neighbor, current.weight + edgeWeight));
                }
            }
        }
    }
};

int main() {
    Graph myGraph;

    // Adding weighted edges to the graph
    myGraph.addEdge(1.29, 1.2, 3);
    myGraph.addEdge(1.2, 3.45, 7);
    myGraph.addEdge(3.45, 3.2, 2);
    myGraph.addEdge(3.45, 5.3, 1);
    myGraph.addEdge(5.3, 6.1, 1);

    // Applying BFS from source node 1.29
    std::cout << "BFS starting from source node 1.29:" << std::endl;
    myGraph.BFS(1.29);

    return 0;
}
