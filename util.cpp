//
// Created by K00wip on 11/12/2020.
//
#include <iostream>
#include <cstdlib>
#include <string>
#include "util.h"

using namespace std;


graph *allocate(graph * mainArray)
{
    string numOfVertex;
    int numOfVertexInt;
    getline(cin, numOfVertex, ' ');
    numOfVertexInt = stoi(numOfVertex);

    mainArray = new graph[numOfVertexInt];

    return mainArray;
}

graph *populate(graph * mainArray)
{
    string edgeCount;
    int edgeCountInt;
    getline(cin, edgeCount);
    edgeCountInt = stoi(edgeCount);

    for(int i = 0; i < edgeCountInt; i++)
    {
        mainArray->insert(mainArray);
    }

    return mainArray;
}
