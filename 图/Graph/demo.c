#include "stdlib.h"
#include "stdio.h"
#include "graph.h"

int main(void)
{
    GNode my_graph;
    ELEMENT_TYPE Start_addr;

    Graph_Init(&my_graph);
    printf("Please input Start place!\r\n");
    scanf("%d",&Start_addr);
    getchar();
    DFS(my_graph,Start_addr);
    printf("\r\n");
    WFS(my_graph,Start_addr);
    printf("\r\n");
    return 0;
}