#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "fcntl.h"
#include "string.h"
#include "graph.h"


VNode New_Vertex(ELEMENT_TYPE val)
{
    VNode op;
    op = (VNode)malloc(sizeof(struct vertex));
    op->node = val;
    op->next = NULL;
    return op;
}

ENode New_Edage(unsigned int vstart,unsigned int vend)
{
    ENode op;
    op = (ENode)malloc(sizeof(struct edage));
    op->node_list[vstart][vend] = 1;
    op->next = NULL;
    return op;
}

void Vist_VList(VNode obj)
{
    while(obj->next != NULL)
    {
        printf("vertex name is:%2d\r\n",obj->node);
        obj = obj->next;
        if(obj->next == NULL)
        {
            printf("vertex name is:%2d\r\n",obj->node);
        }
    }
}

void Vist_Edage(ENode obj)
{
    while(obj->next != NULL)
    {
        for(int i=0;i<MAX_VERTEX;i++)
        for(int j=0;j<MAX_VERTEX;j++)
        {
            if(obj->node_list[i][j])
            {
                printf("vertex_%d link to vertex_%d\r\n",i,j);
            }
        }
        obj = obj->next;
        if(obj->next == NULL)
        {
            for(int i=0;i<MAX_VERTEX;i++)
            for(int j=0;j<MAX_VERTEX;j++)
            {
                if(obj->node_list[i][j])
                {
                    printf("vertex_%d link to vertex_%d\r\n",i,j);
                }
            }
        }
    }
}

int Vertex_Init(VNode *obj,unsigned int vnums,ELEMENT_TYPE *str)
{
    VNode op;
    op = (*obj);
    if(op == NULL)
        op = (VNode)malloc(sizeof(struct vertex));
    op->node = str[0];
    op->next = NULL;

    for(int i=1;i<vnums;i++)
    {
        VNode new = New_Vertex(str[i]);
        op->next = new;
        op = op->next;
    }
    return 0;
}

int Edage_Init(ENode *obj,unsigned int enums,int *Vs,int *Ve)
{
    ENode op;
    op = *obj;
    if(op == NULL)
    {
        op = (ENode)malloc(sizeof(struct edage));
        for(int i=0;i<MAX_VERTEX;i++)
        for(int j=0;j<MAX_VERTEX;j++)
        {
            op->node_list[i][j] = 0;
        }
        op->next = NULL;
    }

    for(int i=0;i<enums;i++)
    {
        ENode new;
        new = New_Edage(Vs[i],Ve[i]);
        op->next = new;
        op = op->next;
    }

    return 0;
}
/* 邻接表 */
void Creat_Graph_Table(GNode *obj,ENode eobj)
{
    GNode op = *obj;
    while(eobj->next != NULL)
    {
        for(int i=0;i<MAX_VERTEX;i++)
        for(int j=0;j<MAX_VERTEX;j++)
        {
            if(eobj->node_list[i][j])
                op->table[i][j] = 1;
        }
        eobj = eobj->next;
        if(eobj->next == NULL)
        {
            for(int i=0;i<MAX_VERTEX;i++)
            for(int j=0;j<MAX_VERTEX;j++)
            {
                if(eobj->node_list[i][j])
                    op->table[i][j] = 1;
            }
        }
    }
}

void Print_Table(GNode op)
{
    int i,j;
    for(i=0;i<MAX_VERTEX;i++)
    {
        for(j=0;j<MAX_VERTEX;j++)
        {
            printf("%2d",op->table[i][j]);
        }    
        printf("\r\n");
    }
}

int Graph_Init(GNode *obj)
{
    /* op ptr */
    GNode op;
    op = (*obj);
    op = (GNode)malloc(sizeof(Graph));

    unsigned int vnums,enums;
    ELEMENT_TYPE getstr[MAX_VERTEX+1] = {0};//MAX_VERTEX
    ELEMENT_TYPE vs[MAX_EDAGE],ve[MAX_EDAGE];

    if(op == NULL)
        return -3;
    printf("please input vertex nums && edage nums!\r\n");
    scanf("%d,%d",&vnums,&enums);
    getchar();
    printf("vn:%d\ten:%d\r\n",vnums,enums);

    op->enums = enums;
    op->vnums = vnums;
    op->v == NULL;
    op->e == NULL;
    /* 结构体中申明了结构体指针时要单独给于空间 */
    /* 结构体中申明了结构体指针时要单独给于空间 */
    /* 结构体中申明了结构体指针时要单独给于空间 */
    op->v = (VNode)malloc(sizeof(struct vertex)/**vnums*/);
    op->e = (ENode)malloc(sizeof(struct edage)/**enums*/);


    printf("please input vertex name in order!\r\n");
    for(int i=0;i<vnums;i++)
    {
        scanf("%d",&getstr[i]);
    }
    Vertex_Init(&op->v,op->vnums,getstr);
    Vist_VList(op->v);

    for(int i=0;i<MAX_VERTEX;i++)
    for(int j=0;j<MAX_VERTEX;j++)
    {
        op->e->node_list[i][j] = 0;
    }
    printf("please input edage such as \"1,2\" refer to vertex1 link to vertex2!\r\n");
    for(int i=0;i<enums;i++)
        scanf("%d,%d",&vs[i],&ve[i]);

    Edage_Init(&op->e,enums,vs,ve);
    Vist_Edage(op->e);
    Creat_Graph_Table(&op,op->e);
    Print_Table(op);
    return 0;
}











