//
// Created by K00wip on 11/12/2020.
//
#include <iostream>
#include <cstdlib>
#include <string>
#include "util.h"

using namespace std;

/**
 * Fn to allocate memory for our adj list pointer
 * @param mainArray takes in the graph array pointer
 * @param numOfVertex passed by ref to hold vertex number, used outside of this method
 * @return
 */
graph *allocate(graph * mainArray, int * numOfVertex)
{
    string numOfVertexString; //string to hold value from input
    getline(cin, numOfVertexString, ' '); //getting input
    *numOfVertex = stoi(numOfVertexString); //dereferenced and assigned int to how many vertex there are

    mainArray = new graph[*numOfVertex]; //dynamic allocation to graph pointer

    return mainArray; //returning pointer
}

/**
 * Fn to create the adj list representation of our graph
 * @param mainArray takes in the graph array pointer
 * @return
 */
graph *populate(graph * mainArray)
{
    string edgeCount; //string to hold value fro input
    int edgeCountInt; //int to hold converted string input
    getline(cin, edgeCount); //getting input
    edgeCountInt = stoi(edgeCount); //converting to int, value to be used as upper bound for loop

    for(int i = 0; i < edgeCountInt; i++)
    {
        mainArray->insert(mainArray); //calling insert fn on graph pointer obj
    }

    return mainArray; //return pointer
}

/**
 * Fn to initialize all vertex objs in a set of vertexes, to be inserted into the minheap later
 * @param vertHoldingArray vertex pointer, vertex set
 * @param adjList graph obj adj list
 * @param sourceVert what vertex we're starting on
 * @param numOfVertex total vertex in graph
 * @return pointer to vertex set
 */
vertex *initialize(vertex * vertHoldingArray, graph * adjList, int sourceVert, int numOfVertex)
{

    vertHoldingArray = new vertex[numOfVertex]; //dynamic allocation of vertex set

    //setting all vertex to max distance and no predecessor
    for(int i = 1; i <= numOfVertex; i++)
    {
        vertHoldingArray[i].vertex = i;
        vertHoldingArray[i].distance = 500000000;
        vertHoldingArray[i].predecessor = NULL;
    }

    //setting source vertex to 0
    vertHoldingArray[sourceVert].distance = 0;

    //return vertex set pointer
    return vertHoldingArray;
}
