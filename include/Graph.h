# pragma once
#include <vector>  
//  return neightbor in vector format
#define MAX_SIZE 200



class Graph {
public:
    int vertexSize=0;
    int edgeSize=0;
    int biggestNum = 0;
    Graph(bool directed);

    Graph() {
        directed=false;
    }
    

    bool isEmpty();
    bool isDirected();
    void addVertex(int newVertex);
    void addEdge(int vertex1,int vertex2);
    void removeVertex(int vertexToRemove);
    void removeEdge(int vertex1, int vertex2);
    int numVertices();
    int numEdges();
    int indegree(int vertex);
    int outdegree(int vertex);
    int degree(int vertex);
    std::vector<int> neighbours(int vertex);
    bool neighbour(int vertex1, int vertex2);
    void visualize(int start, int stop);

private:
    bool directed;
    int adjacencyMatrix[MAX_SIZE][MAX_SIZE] = {};

    std::string padding();

    static std::string padding(int howMuch);
};
