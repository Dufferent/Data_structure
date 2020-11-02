#include "graph.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "fcntl.h"
#include "sys/types.h"

int **tmp_table;

int main(int argc,char** argv)
{
    GRAPH mygraph;
    Graph_Init(&mygraph);
    Covert_Tmp_Table(mygraph);
    DFS(mygraph,0);
    View_Graph_By_Table(mygraph,mygraph.edage);

    Covert_Tmp_Table(mygraph);
    BFS(mygraph,0);

    Covert_Tmp_Table(mygraph);
    DjTsl(mygraph,0);
    return 0;
}