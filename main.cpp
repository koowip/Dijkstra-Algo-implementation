#include <iostream>
#include <cstdlib>
#include <string>
#include "util.h"

using namespace std;

int main() {


    graph *adjList; //Graph pointer to hold Adj list array dynamically
    vertex *initializationSet;
    int numOfVertex = 0; //Int to hold total number of vertex in graph

    adjList = allocate(adjList, &numOfVertex); //util fn to allocate memory on the heap for graph pointer
    adjList = populate(adjList); //util fn that creates the adjlist from the graph input

    dijkstraAlgo(adjList, 23, numOfVertex);

    //This is all testing stuff
    /*MinHeap *a = new MinHeap(5);

    vertex *b = new vertex;
    b->vertex = 1;
    b->distance = 12;
    vertex *c = new vertex;
    c->vertex = 2;
    c->distance = 7;
    vertex *d = new vertex;
    d->vertex = 3;
    d->distance = 9;
    vertex *e = new vertex;
    e->vertex = 4;
    e->distance = 16;
    vertex *f = new vertex;
    f->vertex = 5;
    f->distance = 20;

    a->insert(*b);
    a->insert(*c);
    a->insert(*d);
    a->insert(*e);
    //a->insert(*f);




    for(int i = 0; i < a->currentSize; i++)
    {
        cout << "Vertex Obj: " << i << endl;
        cout << "Index: " << a->minHeap[i].vertex << endl;
        cout << "Distance: " << a->minHeap[i].distance << endl;
        cout << endl;
    }

    //a->minHeap[4].distance = 6;
    //a->minHeap[1].distance = 2;
    //a->heapify(0); //Need to heapify on the parent


    vertex* g = a->extractMin();

    cout << g->distance << endl;

    cout << "\n\nAfter Heapify: \n" << endl;
    cout << endl;

    for(int i = 0; i < a->currentSize; i++)
    {
        cout << "Vertex Obj: " << i << endl;
        cout << "Index: " << a->minHeap[i].vertex << endl;
        cout << "Distance: " << a->minHeap[i].distance << endl;
        cout << endl;
    }
*/



    return 0;
}
