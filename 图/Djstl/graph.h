#ifndef __GRAPH_H
#define __GRAPH_H

#define NUM_OF_VERTEX 6
// #define NUM_OF_EDAGE  (NUM_OF_VERTEX*(NUM_OF_VERTEX-1))

typedef struct {
    int *vertex;
    int **edage;
    int vernum;
    int edgnum;
}GRAPH;

extern int** tmp_table;

int mypow(int x);     //base = 2

void Covert_Tmp_Table(GRAPH obj);
void View_Graph_By_Table(GRAPH obj,int **table);

void Graph_Init(GRAPH *obj);
void DFS(GRAPH obj,int sver);
void BFS(GRAPH obj,int sver);
void DjTsl(GRAPH obj,int vertex);

#endif