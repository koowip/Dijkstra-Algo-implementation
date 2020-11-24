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

/**
 * Fn to insert a vertex obj into the minheap
 * @param addIn
 */
void MinHeap::insert(vertex addIn)
{
    currentSize++; //Increment number of vertexes in heap
    int pos = currentSize - 1; //pos for where to insert new vertex, at bottom of heap
    this->minHeap[pos] = addIn; //putting vertex at bottom spot

    //code maintains min heap rule
    while(pos != 0 && this->minHeap[parent(pos)].distance > this->minHeap[pos].distance)
    {
        swap(&this->minHeap[pos], &this->minHeap[parent(pos)]); //swap with parents if min heap rule broken
        pos = parent(pos); //go to parent pos and test again
    }

}

/**
 * Fn to heapify, maintains min heap rule
 * @param pos
 */
void MinHeap::heapify(int pos)
{
    //Getting adjacent nodes array pos
    int left = leftChild(pos);
    int right = rightChild(pos);
    int smallest = pos;

    //Conditional to see if children are bigger than parent, if so swap and test again
    if( left < currentSize && minHeap[left].distance < minHeap[pos].distance)
    {
        smallest = left;
    }
    if( right < currentSize && minHeap[right].distance < minHeap[smallest].distance)
    {
        smallest = right;
    }
    if( smallest != pos)
    {
       swap(&minHeap[pos], &minHeap[smallest]);
       heapify(smallest);
    }

}

/**
 * Fn to extract top vertex in min heap
 * @return vertex pointer
 */
vertex* MinHeap::extractMin()
{
    //If heap has 1 element, return it
    if(currentSize == 1)
    {
        currentSize--;
        return &minHeap[0];
    }

    //new variable for return, copy data points
    vertex* temp = new vertex;
    temp->vertex = minHeap[0].vertex;
    temp->distance = minHeap[0].distance;
    temp->predecessor = minHeap[0].predecessor;


    //change heap vertex element and decrease heap size
    minHeap[0] = minHeap[currentSize - 1];
    currentSize--;

    //heapify
    heapify(0);

    return temp;
}

void MinHeap::decreaseKey(int vertexSource, int newValue)
{
    int correctHeapIndex;


    for(int i = 0; i < currentSize; i++)
    {

        if(this->minHeap[i].vertex == vertexSource)
            correctHeapIndex = i;
    }

    minHeap[correctHeapIndex].distance = newValue;

    while(minHeap[parent(correctHeapIndex)].distance > minHeap[correctHeapIndex].distance)
    {
        swap(&minHeap[correctHeapIndex], &minHeap[parent(correctHeapIndex)]);
        correctHeapIndex = parent(correctHeapIndex);
    }
    //heapify(parent(correctHeapIndex)); //parent(correctHeaIndex)

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

/**
 * Quick fn to swap 2 vertex pointers
 * @param a
 * @param b
 */
void swap(vertex * a, vertex * b)
{
    vertex temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Fn to see if heap is empty
 * @param que
 * @return
 */
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

vertex* MinHeap::locate(int sourceVertex)
{

    int index = -1;

    for( int i = 0; i <this->currentSize; i++)
    {
        if(this->minHeap[i].vertex == sourceVertex)
        {
            index = i;
        }
    }

    if (index > -1)
    {
       return &minHeap[index];
    }
    else
    {
        return NULL;
    }

}