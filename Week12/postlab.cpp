#include<iostream>
#include<vector>
#include<map>

class Graph {
    private:
        int vertices;
        std::vector<std::vector<double>> adjMatrix;
        std::map<double,int> vertixIndices;

    public:
        Graph(const std::vector<double>& verticesList)
        : vertices(verticesList.size()), adjMatrix(vertices, std::vector<double>(vertices, 0)){
            for(int i=0 ; i<vertices ; i++){
                vertixIndices[verticesList[i]] = i;
            }
        }

        void addEdge(double fromVertex, double toVertex, double weight){
            int fromIndex = vertixIndices[fromVertex];
            int toIndex = vertixIndices[toVertex];
            adjMatrix[fromIndex][toIndex] = weight;
        }
        void displayMatrix(){
            for(int i=0 ; i<vertices ; i++){
                for(int j=0 ; j<vertices ; j++){
                    std::cout<<adjMatrix[i][j]<<" ";
                }
                std::cout<<std::endl;
            }
        }
};

int main(){
    std::vector<double> verticesList = {1.29, 1.2, 6.1, 5.3};

    Graph graph(verticesList);

    graph.addEdge(1.29, 1.2, 1.2);
    graph.addEdge(1.29, 3.459, 3.459);
    graph.addEdge(1.29, 3.2, 3.2);

    graph.addEdge(1.2, 6.1, 6.1);
    graph.addEdge(1.2, 5.3, 5.3);

    graph.addEdge(6.1, 3.2, 3.2);
    graph.addEdge(6.1, 3.459, 3.459);

    graph.addEdge(5.3, 3.2, 3.2);

    graph.displayMatrix();

    return 0;
}