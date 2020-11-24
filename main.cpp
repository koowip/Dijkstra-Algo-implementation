#include "main.h"

using namespace std;

int main() {


    graph *adjList; //Graph pointer to hold Adj list array dynamically
    vertex *initializationSet;
    int numOfVertex = 0; //Int to hold total number of vertex in graph
    int numOfEdges = 0; //Int to hold total number of edges in graph

    adjList = allocate(adjList, &numOfVertex); //util fn to allocate memory on the heap for graph pointer
    adjList = populate(adjList, &numOfEdges); //util fn that creates the adjlist from the graph input

    queryHandler(adjList, numOfVertex, numOfEdges);



    return 0;
}
