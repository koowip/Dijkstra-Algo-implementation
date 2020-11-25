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
 * @return the shortest array with the info about node distance
 */
vertex* dijkstraAlgo(graph * adjList, int sourceVert, int numOfVertex)
{
    //Make a set of vertex objs to be inserted into the minheap
    vertex *initializeSingleSourceSet; //Initialize set to fill heap
    initializeSingleSourceSet = initialize(initializeSingleSourceSet, adjList, sourceVert, numOfVertex); //fills set with empty heap objs and sets source distance to 0


    vertex *shortestPathSet; //Set to hold shortest path
    shortestPathSet = new vertex[numOfVertex + 1]; //Allocate shortest path
    int shortestPathCounter = 1; //variable to increment shortest path address
    MinHeap *priorityQue = new MinHeap(numOfVertex); //PrioQue declaration
    priorityQue = populatePriorityQue(priorityQue, initializeSingleSourceSet, numOfVertex); //Insert the set of vertexes into the minheap


    //loop to empty heap and relax
    while(priorityQue->currentSize != 0)
    {
        shortestPathSet[shortestPathCounter] = *priorityQue->extractMin(); //extract min node into shortest set
        relax(adjList, &shortestPathSet[shortestPathCounter], priorityQue); //relax adjcent nodes in graph
        shortestPathCounter++;
    }


    //delete heap
    delete[] priorityQue;
    return shortestPathSet;

}

/**
 * Functino to populate the heap with the nodes initialized in sourceset
 * @param priorityQue
 * @param initializeSingleSourceSet
 * @param numOfVertex
 * @return returns a pointer to the heap
 */
MinHeap * populatePriorityQue(MinHeap * priorityQue, vertex * initializeSingleSourceSet, int numOfVertex)
{
    for(int i = 1; i <= numOfVertex; i++)
    {
        priorityQue->insert(initializeSingleSourceSet[i]); //insert nodes into heap
    }

    return priorityQue;
}

/**
 * Function to relax all nodes adjcent to source
 * @param adjList
 * @param source
 * @param priorityQue
 */
void relax(graph* adjList, vertex* source, MinHeap* priorityQue)
{

    //int holders for graph obj information
    int edgeVertex;
    int edgeWeight;

    //temp node to hold adjcent graph obj heap node
    vertex* tempVertexObj;

    //choosing the right pos in graph array
    graph* temp = &adjList[source->vertex];


    while( temp->next != NULL)
    {

        //copy information from graph to temps for comparison
        edgeVertex = temp->next->nextVert;
        edgeWeight =  temp->next->weight;

        //copy heap obj address
        tempVertexObj = priorityQue->locate(edgeVertex);

        //if distance traveled is less than heap nodes distance then do
        if(tempVertexObj != NULL && ((edgeWeight + source->distance) < tempVertexObj->distance))
        {
            tempVertexObj->distance = edgeWeight + source->distance; //heap obj gets new distance value
            tempVertexObj->predecessor = source; //heap obj gets pred vertex node pointer
            priorityQue->decreaseKey(edgeVertex, tempVertexObj->distance); //decrease key of heap obj and heapify
        }

        temp = temp->next; //iterate thru graph objs that are adjacent
    }

}

/**
 * Function to handle queries
 * @param adjList
 * @param numOfVertex
 * @param numOfEdges
 */
void queryHandler(graph* adjList, int numOfVertex, int numOfEdges)
{
    //various basics to hold temp information
    int sentinel = 0;
    string query;
    string queryHelper;
    string findQueryNum1;
    string findQueryNum2;
    string findQueryNum3;
    int findQueryAr[3];


    //while sentinel value is not set (via the stop input)
    while(!sentinel)
    {
        getline(cin, query);

        //determine which command
        if(query[0] == 'w' || query[0] == 'W')
        {
            printGraph(adjList, numOfVertex, numOfEdges); //prints graph
        }
        if(query[0] == 'f' || query[0] == 'F')
        {
            //query substrings to parse input
            queryHelper = query.substr(5);
            findQueryNum1 = queryHelper.substr(0,queryHelper.find(' '));
            findQueryNum2 = queryHelper.substr(findQueryNum1.length() + 1);
            findQueryNum2 = findQueryNum2.substr(0, findQueryNum2.find(' '));
            findQueryNum3 = queryHelper.substr(queryHelper.find_last_of(' ') + 1);

            //error checking
            if(stoi(findQueryNum1) < 1)
            {
                printf("Command: find %d %d %d", stoi(findQueryNum1), stoi(findQueryNum2), stoi(findQueryNum3));
                cout << endl;
                cout << "Error: one or more invalid nodes" << endl;

                if(stoi(findQueryNum3) < 0 || stoi(findQueryNum3) > 1)
                {
                    cout << "Error: invalid flag value" << endl;
                }
            }
            else if(stoi(findQueryNum2) < 1 || stoi(findQueryNum2) > numOfVertex)
            {
                printf("Command: find %d %d %d", stoi(findQueryNum1), stoi(findQueryNum2), stoi(findQueryNum3));
                cout << endl;
                cout << "Error: one or more invalid nodes" << endl;

                if(stoi(findQueryNum3) < 0 || stoi(findQueryNum3) > 1)
                {
                    cout << "Error: invalid flag value" << endl;
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
                findQuery(adjList, findQueryAr, numOfVertex); //if no error find the query
            }
        }
        if(query[0] == 's')
        {
            cout << "Command: stop" << endl;
            delete[] adjList; //free graph memory before program end
            sentinel = 1; //change sentinel value to end while loop and end program
        }
    }
}

/**
 * Function to print all the graph elements
 * @param adjList
 * @param numOfVertex
 * @param numOfEdges
 */
void printGraph(graph* adjList, int numOfVertex, int numOfEdges)
{
    //various basics
    int adjVertex;
    int adjWeight;
    graph* temp;


    cout << "Command: write" << endl;
    cout << numOfVertex << " " << numOfEdges << endl;

    for(int i = 1; i <= numOfVertex; i++)
    {
        cout << i << " : ";

        temp = adjList[i].next; //while the adj list is not empty print the edge information

        while(temp != NULL)
        {
            printf("(%d; %d)", temp->nextVert, temp->weight);
            temp = temp->next;

            //if statement for formatting
            if(temp != NULL)
            {
                cout << "; ";
            }
        }
        cout << endl;
    }

}

/**
 * function that does the find query computation
 * @param adjList
 * @param findQueryAr
 * @param numOfVertex
 */
void findQuery(graph * adjList, int findQueryAr[], int numOfVertex)
{
    vertex * finalSet;
    int targetSpotInFinalSet;
    int  pathAr[numOfVertex];
    int counter = 0;
    finalSet = dijkstraAlgo(adjList, findQueryAr[0], numOfVertex); //dijkstras algo to fill finalSet with the vertexes and their distances from the input source node

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
        if(finalSet[targetSpotInFinalSet].distance == 500000000)
        {
            printf("Error: node %d not reachable from node %d", findQueryAr[1], findQueryAr[0]);
            cout << endl;
        }
        else
        {
            printf("Length: %d", finalSet[targetSpotInFinalSet].distance);
            cout << endl;
        }

    }
    else
    {

        vertex* temp = &finalSet[targetSpotInFinalSet];

        while(temp != NULL)
        {
            pathAr[counter] = temp->vertex;
            temp = temp->predecessor;
            counter++;
        }

        if(finalSet[targetSpotInFinalSet].distance == 500000000)
        {
            printf("Error: node %d not reachable from node %d", findQueryAr[1], findQueryAr[0]);
            cout << endl;
        }
        else
        {
            cout << "Path: ";

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

}