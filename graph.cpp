//
// Created by K00wip on 11/4/2020.
//
#include <string>
#include <iostream>
#include "graph.h"

using namespace std;

/**
 * Graph constructor with values set to NULL / 0
 */
graph::graph()
{
    vertex = 0;
    nextVert = 0;
    weight = 0;
    next = nullptr;

}

/**
 * Graph constructor with values given
 * @param vertex1
 * @param nextVert1
 * @param weight1
 */
graph::graph(int vertex1, int nextVert1, int weight1)
{
    this->vertex = vertex1;
    this->nextVert = nextVert1;
    this->weight = weight1;
    next = nullptr;
}

/**
 * Fn to insert an item into the graph array using linked list representation
 * @param mainArray
 */
void graph::insert(graph *mainArray)
{
    //All these values are used for inut from the txt file
    int currentVertexInt;
    int currentWeightInt;
    int currentNextVertInt;
    string currentVertex;
    string currentWeight;
    string currentNextVert;

    //All these getlines convert string values to ints
    getline(cin, currentVertex, ' ');
    currentVertexInt = stoi(currentVertex);

    getline(cin, currentNextVert, ' ');
    currentNextVertInt = stoi(currentNextVert);

    getline(cin, currentWeight);
    currentWeightInt = stoi(currentWeight);



    graph *newNode = new graph(); //Heap allocating new graph obj
    graph * temp; //Temp graph obj for use when iterating thru the linked list

    //Assigning values from input to new graph obj
    newNode->vertex = currentVertexInt;
    newNode->nextVert = currentNextVertInt;
    newNode->weight = currentWeightInt;


    //Logic to store graph obj of number (vertex) into the same number (vertex) of our
    //graph array
    if(!mainArray[currentVertexInt].next)
    {
        mainArray[currentVertexInt].next = newNode; //Obj becomes head of linked list
    }
    else
    {
        temp = mainArray[currentVertexInt].next; //Iterate thru list until you find an empty spot

        while(temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode; //obj is put at the first available empty spot

    }

}
