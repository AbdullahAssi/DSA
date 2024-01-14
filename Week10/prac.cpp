#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <limits>

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
        std::queue<std::pair<double, double>> bfsQueue;

        visited.insert(startNode);
        bfsQueue.push(std::make_pair(startNode, 0.0));

        while (!bfsQueue.empty()) {
            double current = bfsQueue.front().first;
            double currentWeight = bfsQueue.front().second;
            std::cout << "Node: " << current << " | Weight: " << currentWeight << std::endl;
            bfsQueue.pop();

            for (const auto& neighborPair : adjacencyList[current]) {
                double neighbor = neighborPair.first;
                double edgeWeight = neighborPair.second;

                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    bfsQueue.push(std::make_pair(neighbor, currentWeight + edgeWeight));
                }
            }
        }
    }
};

int main() {
    // Creating a graph with weights
    Graph myGraph;

    // Adding weighted edges to the graph
    myGraph.addEdge(1.29, 1.2, 3);
    myGraph.addEdge(1.2, 3.4, 7);
    myGraph.addEdge(3.4, 3.2, 2);
    myGraph.addEdge(3.4, 5.3, 1);
    myGraph.addEdge(5.3, 6.1, 1);

    // Applying BFS from source node 1.29
    std::cout << "BFS starting from source node 1.29:" << std::endl;
    myGraph.BFS(1.29);

    return 0;
}