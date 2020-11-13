//
// Created by K00wip on 11/4/2020.
//

#ifndef CSE310_PROJ3_GRAPH_H
#define CSE310_PROJ3_GRAPH_H

class graph
{
public:
    int vertex;
    int nextVert;
    int weight;
    graph *next;

    graph();
    graph(int vertex, int nextVert, int edge);
    void insert(graph * mainArray);
};

#endif //CSE310_PROJ3_GRAPH_H
