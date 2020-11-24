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

    mainArray = new graph[*numOfVertex + 1]; //dynamic allocation to graph pointer

    return mainArray; //returning pointer
}

/**
 * Fn to create the adj list representation of our graph
 * @param mainArray takes in the graph array pointer
 * @return
 */
graph *populate(graph * mainArray, int * numOfEdges)
{
    string edgeCount; //string to hold value fro input
    getline(cin, edgeCount); //getting input
    *numOfEdges = stoi(edgeCount); //converting to int, value to be used as upper bound for loop

    for(int i = 0; i < *numOfEdges; i++)
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

    vertHoldingArray = new vertex[numOfVertex + 1]; //dynamic allocation of vertex set

    int x;
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

/**
 * Algo that finds the shortest distance between a source and another node on the graph
 * @param adjList
 * @param sourceVert
 * @param numOfVertex
 */
vertex* dijkstraAlgo(graph * adjList, int sourceVert, int numOfVertex)
{
    //Make a set of vertex objs to be inserted into the minheap
    vertex *initializeSingleSourceSet;
    initializeSingleSourceSet = initialize(initializeSingleSourceSet, adjList, sourceVert, numOfVertex);


    vertex *shortestPathSet; //Set to hold shortest path
    shortestPathSet = new vertex[numOfVertex + 1]; //Allocate shortest path
    int shortestPathCounter = 1;
    MinHeap *priorityQue = new MinHeap(numOfVertex); //PrioQue declaration
    priorityQue = populatePriorityQue(priorityQue, initializeSingleSourceSet, numOfVertex); //Insert the set of vertexes into the minheap

    //Code to test prio que is correct
    /*for ( int i = 0; i < priorityQue->currentSize; i++)
    {
        cout << "Index: " << priorityQue->minHeap[i].vertex << endl;
        cout << "Distance: " << priorityQue->minHeap[i].distance << endl;
    }*/

    cout << endl;

    while(priorityQue->currentSize != 0)
    {
        shortestPathSet[shortestPathCounter] = *priorityQue->extractMin();
        relax(adjList, &shortestPathSet[shortestPathCounter], priorityQue);
        shortestPathCounter++;
    }


    /*for ( int i = 1; i <= numOfVertex; i++)
    {
        cout << "Index:    " << shortestPathSet[i].vertex << endl;
        cout << "Distance: " << shortestPathSet[i].distance << endl;
    }*/

    delete[] priorityQue;
    return shortestPathSet;

}

MinHeap * populatePriorityQue(MinHeap * priorityQue, vertex * initializeSingleSourceSet, int numOfVertex)
{
    for(int i = 1; i <= numOfVertex; i++)
    {
        priorityQue->insert(initializeSingleSourceSet[i]);
    }

    return priorityQue;
}

void relax(graph* adjList, vertex* source, MinHeap* priorityQue)
{

    int edgeVertex;
    int edgeWeight;

    vertex* tempVertexObj;

    graph* temp = &adjList[source->vertex];

    while( temp->next != NULL)
    {

        edgeVertex = temp->next->nextVert;
        edgeWeight =  temp->next->weight;


        tempVertexObj = priorityQue->locate(edgeVertex);

        if(tempVertexObj != NULL && ((edgeWeight + source->distance) < tempVertexObj->distance))
        {
            tempVertexObj->distance = edgeWeight + source->distance;
            tempVertexObj->predecessor = source;
            priorityQue->decreaseKey(edgeVertex, tempVertexObj->distance);
        }
        temp = temp->next;
    }

}

void queryHandler(graph* adjList, int numOfVertex, int numOfEdges)
{
    int sentinel = 0;
    string query;
    string queryHelper;
    string findQueryNum1;
    string findQueryNum2;
    string findQueryNum3;
    int findQueryAr[3];

    while(!sentinel)
    {
        getline(cin, query);


        if(query[0] == 'w')
        {
            printGraph(adjList, numOfVertex, numOfEdges);
        }
        if(query[0] == 'f')
        {
            queryHelper = query.substr(5);
            //cout << queryHelper << endl;
            findQueryNum1 = queryHelper.substr(0,queryHelper.find(' '));
            //cout << findQueryNum1 << endl;
            findQueryNum2 = queryHelper.substr(findQueryNum1.length() + 1);
            findQueryNum2 = findQueryNum2.substr(0, findQueryNum2.find(' '));
            //cout << findQueryNum2 << endl;
            findQueryNum3 = queryHelper.substr(queryHelper.find_last_of(' ') + 1);
            //cout << findQueryNum3 << endl;

            if(stoi(findQueryNum1) < 1)
            {
                printf("Command: find %d %d %d", stoi(findQueryNum1), stoi(findQueryNum2), stoi(findQueryNum3));
                cout << endl;
                cout << "Error: one or more invalid nodes" << endl;

                if(stoi(findQueryNum3) < 0 || stoi(findQueryNum3) > 1)
                {
                    cout << "Error: invalid flag value";
                }
            }
            else if(stoi(findQueryNum2) < 1)
            {
                printf("Command: find %d %d %d", stoi(findQueryNum1), stoi(findQueryNum2), stoi(findQueryNum3));
                cout << endl;
                cout << "Error: one or more invalid nodes" << endl;

                if(stoi(findQueryNum3) < 0 || stoi(findQueryNum3) > 1)
                {
                    cout << "Error: invalid flag value";
                }
            }
            else if(stoi(findQueryNum3) < 0 || stoi(findQueryNum3) > 1)
            {
                printf("Command: find %d %d %d", stoi(findQueryNum1), stoi(findQueryNum2), stoi(findQueryNum3));
                cout << endl;
                cout << "Error: invalid flag value" << endl;
            }
            else
            {
                findQueryAr[0] = stoi(findQueryNum1);
                findQueryAr[1] = stoi(findQueryNum2);
                findQueryAr[2] = stoi(findQueryNum3);
                findQuery(adjList, findQueryAr, numOfVertex);
            }
        }
        if(query[0] == 's')
        {
            cout << "Command: stop" << endl;
            delete[] adjList;
            sentinel = 1;
        }
    }


}

void printGraph(graph* adjList, int numOfVertex, int numOfEdges)
{
    int adjVertex;
    int adjWeight;
    graph* temp;

    cout << "Command: write" << endl;
    cout << numOfVertex << " " << numOfEdges << endl;

    for(int i = 1; i <= numOfVertex; i++)
    {
        cout << i << " : ";

        temp = adjList[i].next;

        while(temp != NULL)
        {
            printf("(%d; %d)", temp->nextVert, temp->weight);
            temp = temp->next;

            if(temp != NULL)
            {
                cout << "; ";
            }
        }
        cout << endl;
    }

}

void findQuery(graph * adjList, int findQueryAr[], int numOfVertex)
{
    vertex * finalSet;
    int targetSpotInFinalSet;
    int  pathAr[numOfVertex];
    int counter = 0;
    finalSet = dijkstraAlgo(adjList, findQueryAr[0], numOfVertex);

    printf("Command: find %d %d %d", findQueryAr[0], findQueryAr[1],findQueryAr[2]);
    cout << endl;

    for(int i = 1; i <= numOfVertex; i++)
    {
        if(finalSet[i].vertex == findQueryAr[1])
        {
            targetSpotInFinalSet = i;
        }
    }

    if (findQueryAr[2])
    {
        printf("Length: %d", finalSet[targetSpotInFinalSet].distance);
        cout << endl;
    }
    else
    {
        cout << "Path: ";

        vertex* temp = &finalSet[targetSpotInFinalSet];

        while(temp != NULL)
        {
            pathAr[counter] = temp->vertex;
            temp = temp->predecessor;
            counter++;
        }


        for(int i = counter - 1; i >= 0; i--)
        {
            cout << pathAr[i];

            if(i != 0)
            {
                cout << ";";
            }
        }

        cout << endl;
    }

}