//
// Created by K00wip on 11/4/2020.
//

#ifndef CSE310_PROJ3_HEAP_H
#define CSE310_PROJ3_HEAP_H

#include "vertex.h"

class MinHeap
{
public:
    vertex *minHeap;
    int maxSize;
    int currentSize;

    MinHeap(int size);
    void insert(vertex k);
};
#endif //CSE310_PROJ3_HEAP_H
