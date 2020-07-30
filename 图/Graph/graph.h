#ifndef __GRAPH_H
#define __GRAPH_H

/* data type */
#define ELEMENT_TYPE int 
#define MAX_VERTEX   6
#define MAX_EDAGE    30
/* data structure */
typedef struct edage{
    ELEMENT_TYPE node_list[MAX_VERTEX][MAX_VERTEX];//表示两顶点间的边,有边为1，否则0
    struct edage *next;//下一条边
}*ENode;

typedef struct vertex{
    ELEMENT_TYPE node;//节点名称
    struct vertex *next;//下一个节点
}*VNode;

typedef struct{
    ENode e;//边
    VNode v;//顶点
    ELEMENT_TYPE table[MAX_VERTEX][MAX_VERTEX];
    unsigned int vnums;
    unsigned int enums;
}Graph,*GNode;

/* op */
int Graph_Init(GNode *obj);
void Vist_VList(VNode obj);
void DFS(GNode obj,int vertex);
void WFS(GNode obj,int vertex);
#endif