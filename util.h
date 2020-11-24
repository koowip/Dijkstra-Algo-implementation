//
// Created by K00wip on 11/12/2020.
//
#include <string>
#include "graph.h"
#include "heap.h"

using namespace std;


#ifndef CSE310_PROJ3_UTIL_H
#define CSE310_PROJ3_UTIL_H


/**
 * Header file containing utility functions
 * @param mainArray
 * @return
 */
graph* allocate(graph * mainArray, int * numOfVertex);
graph* populate(graph * mainArray, int * munOfEdges);
vertex* initialize(vertex * vertHoldingArray, graph * adjList, int sourceVert, int numOfVertex);
vertex* dijkstraAlgo(graph * adjList, int sourceVert, int numOfVertex);
MinHeap* populatePriorityQue(MinHeap * priorityQue, vertex * initializeSingleSourceSet, int numOfVertex);
void relax(graph* adjList, vertex* source, MinHeap* priorityQue);
void queryHandler(graph* adjList, int numOfVertex, int numOfEdges);
void printGraph(graph * adjList, int numOfVertex, int numOfEdges);
void findQuery(graph * adjList, int findQueryAr[], int numOfVertex);

#endif //CSE310_PROJ3_UTIL_H
