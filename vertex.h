//
// Created by K00wip on 11/13/2020.
//

#ifndef CSE310_PROJ3_VERTEX_H
#define CSE310_PROJ3_VERTEX_H

struct vertex
{
public:
    int vertex;
    struct vertex * predecessor;
    int distance;
};

#endif //CSE310_PROJ3_VERTEX_H
