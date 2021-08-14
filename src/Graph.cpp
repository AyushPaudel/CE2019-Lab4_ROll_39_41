#include <iostream>
#include "../include/Graph.h"
#include <algorithm>  // for std::find

bool Graph::isEmpty() {
    return (vertexSize == 0);
}

bool Graph::isDirected() {
    return directed;
}

void Graph::addVertex(int newVertex) {
    vertexSize+=1;
    adjacencyMatrix[newVertex][newVertex] = 1;
    if(newVertex > biggestNum){
        biggestNum = newVertex;
    }
}


void Graph::removeVertex(int vertexToRemove) {
    if(adjacencyMatrix[vertexToRemove][vertexToRemove] != 0) {
        adjacencyMatrix[vertexToRemove][vertexToRemove] = 0;
        //sweep the entire row
        for(int i = 0 ; i < MAX_SIZE; i++){
            if(adjacencyMatrix[vertexToRemove][i] != 0 && i != vertexToRemove)
                removeEdge(vertexToRemove,i);
        }
            for(int i = 0 ; i < MAX_SIZE; i++){
                if(adjacencyMatrix[i][vertexToRemove] != 0 && i != vertexToRemove)
                    removeEdge(i,vertexToRemove);
                }

        vertexSize -= 1;
        // check for connected edges too
    }
    if(vertexToRemove == biggestNum){
        int i = biggestNum;
        while(i >= 1){
            if(adjacencyMatrix[i][i] != 0){
                biggestNum = i;
                return;
            }
           i--;
        }
        biggestNum = 0;
    }
}



void Graph::addEdge(int vertex1, int vertex2) {
    adjacencyMatrix[vertex1][vertex2] = 1;
    if(!isDirected()) {
        adjacencyMatrix[vertex2][vertex1] = 1;
    }
    edgeSize+=1;
}


int Graph::numVertices() {
    return vertexSize;
}

void Graph::removeEdge(int vertex1, int vertex2) {
    if(adjacencyMatrix[vertex1][vertex2] != 0){
        adjacencyMatrix[vertex1][vertex2] = 0;
        edgeSize -=1;
        if(!isDirected()){
            adjacencyMatrix[vertex2][vertex1] = 0;
        }
    }
}

int Graph::numEdges() {
    return edgeSize;
}

int Graph::indegree(int vertex) {
    int counter=0;
    for(int i = 0 ;i < MAX_SIZE; i++){
        if(adjacencyMatrix[i][vertex] != 0 && i != vertex){
            counter++;
        }
    }
    return counter;
}


int Graph::degree(int vertex) {
    if(isDirected()){
       return indegree(vertex) + outdegree(vertex);
    }
      return outdegree(vertex);

}


bool Graph::neighbour(int vertex1, int vertex2) {
    if(isDirected())
        return (adjacencyMatrix[vertex1][vertex2] != 0);
    else
        return (adjacencyMatrix[vertex1][vertex2] != 0) && (adjacencyMatrix[vertex2][vertex1] != 0);
}

std::string Graph::padding(int howMuch){
    std::string data = "";

    for(int i = 0 ; i < howMuch; i++){
        data+=" ";
    }

    return data;
}
void Graph::visualize(int start, int stop) {
    //find largest size
    int bBuf = biggestNum;
    int size = 0;
    while(bBuf > 0){
        size++;
        bBuf /= 10;
    }

    for(int i = start;i <= stop;i++) {
        if(i == start) {
            std::cout << "  ";
        }
        std::cout  << i << padding(size) << " " ;
    }
    std::cout << std::endl;
    for(int i = start;i <= stop;i++){
        for(int j = start;j <= stop;j++){
            if(j == start){
                std::cout << i << " ";
            }
            int f = i;
            int sizei = 0;
            while(f > 0){
                sizei++;
                f /= 10;
            }

            std::cout << adjacencyMatrix[i][j] << padding(size+sizei-1) <<  " ";
        }
        std::cout << std::endl;
    }

}


int Graph::outdegree(int vertex) {
    int counter=0;
    for(int i = 0 ;i < MAX_SIZE; i++){
        if(adjacencyMatrix[vertex][i] != 0 && i != vertex){
            counter++;
        }
    }
    return counter;
}


std::vector<int> Graph::neighbours(int vertex) {
    std::vector<int> n_vec;

    for(int i = 0 ;i < MAX_SIZE; i++){
        if(adjacencyMatrix[vertex][i] != 0 && i != vertex) {
            n_vec.push_back(i);
        }
        //in neighbours for directed Graph
        if(isDirected()) {
            if (adjacencyMatrix[i][vertex] != 0 && i != vertex) {
                if(std::find(n_vec.begin(),n_vec.end(),i) == n_vec.end()){   
                       n_vec.push_back(i);
                    }  // std::find used from algorithm
            }
        }
    }
    return n_vec;
}


Graph::Graph(bool directed) : directed(directed) {
    for (int i = 0; i < MAX_SIZE; i++)
      for (int j = 0; j < MAX_SIZE; j++)
        adjacencyMatrix[i][j] = 0;
}

void Graph::GenerateRandomGraphs(const int NOE, int NOV)
{
	int i, j, edge[NOE][2], count;
	i = 0;
	// connecting two vertex.
	while(i < NOE)
	{
		edge[i][0] = rand()%NOV+1;
		edge[i][1] = rand()%NOV+1;
 
		if(edge[i][0] == edge[i][1])
			continue;
		else
		{
			for(j = 0; j < i; j++)
			{
				if((edge[i][0] == edge[j][0] && edge[i][1] == edge[j][1]) || (edge[i][0] == edge[j][1] && edge[i][1] == edge[j][0]))
					i--;
			}
		}
		i++;
	}
 
	std::cout<<"The generated random random graph is:\n ";
	for(i = 0; i < NOV; i++)
	{
		count = 0;
		std::cout<<"\n\t"<<i+1<<"-> { ";
		for(j = 0; j < NOE; j++)
		{
			if(edge[j][0] == i+1)
			{
				std::cout<<edge[j][1]<<" ";
				count++;
			}
			else if(edge[j][1] == i+1)
			{
				std::cout<<edge[j][0]<<" ";
				count++;
			}
			else if(j == NOE-1 && count == 0)
				std::cout<<"Isolated Vertex!";
		}
		std::cout<<"}";
	}	
}







