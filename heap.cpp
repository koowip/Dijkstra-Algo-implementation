//
// Created by K00wip on 11/4/2020.
//
#include <string>
#include "heap.h"

/**
 * Creating a MinHeapObj
 * @param size
 */
MinHeap::MinHeap(int size)
{
    minHeap = new vertex[size];
    maxSize = size;
    currentSize = 0;
}


void MinHeap::insert(vertex k)
{


    currentSize++;

}