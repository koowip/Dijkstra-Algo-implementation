//
// Created by K00wip on 11/4/2020.
//
#include <string>
#include <iostream>
#include "graph.h"

using namespace std;


graph :: graph()
{
    vertex = 0;
    nextVert = 0;
    weight = 0;
    next = nullptr;

}

graph::graph(int vertex, int nextVert, int weight)
{
    vertex = vertex;
    nextVert = nextVert;
    weight = weight;
    next = nullptr;
}

void graph::insert(graph *mainArray)
{
    int currentVertexInt;
    int currentWeightInt;
    int currentNextVertInt;
    string currentVertex;
    string currentWeight;
    string currentNextVert;

    getline(cin, currentVertex, ' ');
    currentVertexInt = stoi(currentVertex);

    getline(cin, currentNextVert, ' ');
    currentNextVertInt = stoi(currentNextVert);

    getline(cin, currentWeight);
    currentWeightInt = stoi(currentWeight);

    cout << currentVertexInt << ' ';
    cout << currentNextVertInt << ' ';
    cout << currentWeightInt << endl;


    graph *newNode = new graph();
    graph * temp;

    newNode->vertex = currentVertexInt;
    newNode->nextVert = currentNextVertInt;
    newNode->weight = currentWeightInt;

    cout << "newNode Vert: " << newNode->vertex << endl;
    cout << "newNode nextVert: " << newNode->nextVert << endl;
    cout << "newNode Weight: " << newNode->weight << endl;


    if(!mainArray[currentVertexInt].next)
    {
        mainArray[currentVertexInt].next = newNode;
    }
    else
    {
        temp = mainArray[currentVertexInt].next;

        while(temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;

    }

}
