//
// Created by K00wip on 11/4/2020.
//
#include <string>
#include <iostream>
#include "heap.h"

using namespace std;

void swap(vertex * a, vertex * b);

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


void MinHeap::insert(vertex addIn)
{
    currentSize++;
    int pos = currentSize - 1;
    this->minHeap[pos] = addIn;

    while(pos != 0 && this->minHeap[parent(pos)].distance > this->minHeap[pos].distance)
    {
        swap(&this->minHeap[pos], &this->minHeap[parent(pos)]);
        pos = parent(pos);
    }

}

int MinHeap::parent(int i)
{
    return (i - 1) / 2;
}

int MinHeap::leftChild(int i)
{
    return (2 * i) + 1;
}

int MinHeap::rightChild(int i)
{
    return (2 * i) + 2;
}

void swap(vertex * a, vertex * b)
{
    vertex temp = *a;
    *a = *b;
    *b = temp;
}

int MinHeap::isEmpty(MinHeap* que)
{
    if (que->currentSize == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}