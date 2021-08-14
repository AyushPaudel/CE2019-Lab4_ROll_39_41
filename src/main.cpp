#include <iostream>
#include "../include/Graph.h"
#include <string>


int main()
{
    
    Graph plot;
    //adding vertex
    std::cout << "Creating graph...\n" << std::endl;
    plot.addVertex(1);
    plot.addVertex(2);
    plot.addVertex(3);
    plot.addVertex(4);
    plot.addVertex(5);
    std::cout << "The total number of the vertices in the graph is " << plot.numVertices() << ".\n" << std::endl;

    //since no edges are linked between the vertices so it forms to give disconnected graph or null graph where every vertices are connected components in itself.
  /*    1     3 
                        4
                    5
        2
   */
    
    plot.addEdge(1,2);
    plot.addEdge(1,3);
    plot.addEdge(2,3);
    plot.addEdge(3,4);
    plot.addEdge(5,4);
    std::cout << "The total number of the edges in the graph is " << plot.numEdges() << ".\n" << std::endl;

//now the edges between the vertices are connected it transfigures from disconnected to connected graph.

  /*    1 ->  3  
        |     ʌ |
        |    /  v
        |   /   4 <--- 5
        |  /         
        v /
        2
   */

    
    std::cout << "Indegree of the vertex 4 in the graph is " << plot.indegree(4) << ".\n" << std::endl;
    std::cout << "Outdegree of the vertex 1 in the graph is " << plot.outdegree(1) << ".\n" << std::endl;
    std::cout << "Degree of the vertex 4 in the graph is " << plot.degree(4) << ".\n" << std::endl;
    plot.removeVertex(50);

     /* 1 ->  3  
        |     ʌ |
        |    /  v
        |   /   4 <--- vertex(5) is removed but edge is still there 
        |  /         
        v /
        2
   */
    plot.removeEdge(5,4); //removes the edge directed from 50 to 40

    std::cout << "The total number of the vertices in the graph is " << plot.numVertices() << ".\n" << std::endl;
    std::cout << "The total number of the edges in the graph is " << plot.numEdges() << ".\n" << std::endl;
    std::cout << "Indegree of the vertex 4 in the graph is " << plot.indegree(4) << ".\n" << std::endl;
    std::cout << "Outdegree of the vertex 1 in the graph is " << plot.outdegree(1) << ".\n" << std::endl;
    std::cout << "Degree of the vertex 4 in the graph is " << plot.degree(4) << ".\n" << std::endl;

    if(plot.neighbour(3,5))
    {
      std::cout << "Provided vertices are neighbour nodes." << std::endl;
    }
    else
    {
      std::cout << "Provided vertices are not neighbour nodes.\n" << std::endl;
    }
    std::cout << "Adjanceny matrix is shown below.\n" << std::endl;
    plot.visualize(1,5);
    std::cout << std::endl;
    std::cout << "\n-----------------------------------------\n" << std::endl;

    int n, i, e, v;
    std::cout << "Enter the number of the vertex in the graph\n" ;
    std::cin >> v;
    std::cout << "Enter the number of the edges in the graph\n" ;
    std::cin >> e;
    std::cout<<"Random graph generation: \n";
    std::cout<<"The graph has "<<v<<" vertices.\n";
    std::cout<<"The graph has "<<e<<" edges.\n";
    plot.GenerateRandomGraphs(e, v); // generates undirected graph
    std::cout << "\nAdjanceny matrix is shown below.\n" << std::endl;
    plot.visualize(1,v);
    
}
