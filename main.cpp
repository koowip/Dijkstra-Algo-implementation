#include <iostream>
#include <cstdlib>
#include <string>
#include "util.h"

using namespace std;

int main() {


    graph *adjList; //Graph pointer to hold Adj list array dynamically
    vertex *initializationSet;
    int numOfVertex = 0; //Int to hold total number of vertex in graph

    adjList = allocate(adjList, &numOfVertex); //util fn to allocate memory on the heap for graph pointer
    adjList = populate(adjList); //util fn that creates the adjlist from the graph input


    dijkstraAlgo(adjList, 1, numOfVertex);


    return 0;
}
