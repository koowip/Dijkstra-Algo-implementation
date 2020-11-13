#include <iostream>
#include <cstdlib>
#include <string>
#include "util.h"

using namespace std;

int main() {



    graph *adjList;
    adjList = allocate(adjList);
    adjList = populate(adjList);

    cout << adjList[1].weight << endl;
    cout << adjList[1].next->weight << endl;
    cout << adjList[1].next->next->weight << endl;





    return 0;
}
