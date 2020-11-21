//
// Created by K00wip on 11/12/2020.
//

#include "graph.h"
#include "heap.h"


#ifndef CSE310_PROJ3_UTIL_H
#define CSE310_PROJ3_UTIL_H


/**
 * Header file containing utility functions
 * @param mainArray
 * @return
 */
graph* allocate(graph * mainArray, int * numOfVertex);
graph* populate(graph * mainArray);
vertex* initialize(vertex * vertHoldingArray, graph * adjList, int sourceVert, int numOfVertex);


#endif //CSE310_PROJ3_UTIL_H
