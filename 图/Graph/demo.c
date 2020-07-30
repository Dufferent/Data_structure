#include "stdlib.h"
#include "stdio.h"
#include "graph.h"

int main(void)
{
    GNode my_graph;

    Graph_Init(&my_graph);
    DFS(my_graph,0);
    printf("\r\n");
    return 0;
}