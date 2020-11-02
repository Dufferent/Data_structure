#include "graph.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "fcntl.h"
#include "sys/types.h"

/* operations */

void Graph_Init(GRAPH *obj)
{
    printf("please input vertex nums!\r\n");
    scanf("%d",&(*obj).vernum);
    printf("please input edage nums!\r\n");
    scanf("%d",&(*obj).edgnum);
    // [分配空间]
    (*obj).vertex = (int*)malloc(sizeof(int)*(*obj).vernum);
    (*obj).edage  = (int**)malloc(sizeof(int*)*(*obj).vernum);
    for(int i=0;i<(*obj).vernum;i++)
        ((*obj).edage[i]) = (int*)malloc(sizeof(int)*(*obj).vernum);

    printf("please input vertex by order!\r\nsuch:1[\\n] 2[\\n] ...\r\n");
    for(int i=0;i<(*obj).vernum;i++)
        scanf("%d",&(*obj).vertex[i]);
    
    for(int i=0;i<(*obj).vernum;i++)
        printf("[vertex list]:<%d>\r\n",(*obj).vertex[i]);

    printf("please input edage by order!\r\nsuch:<vertex1>,<val>,<vertex2>[\\n]...\r\n");
    for(int i=0;i<(*obj).edgnum;i++)
    {
        int v1,v2;
        int val;
        scanf("%d,%d,%d",&v1,&val,&v2);
        (*obj).edage[v1][v2] = val;
    }
    for(int i=0;i<(*obj).vernum;i++)
    {
        for(int j=0;j<(*obj).vernum;j++)
        {
            if(!(*obj).edage[i][j])
                (*obj).edage[i][j] = 100;
        }
    }
    for(int i=0;i<(*obj).vernum;i++)
    {
        for(int j=0;j<(*obj).vernum;j++)
        {
            printf("%4d",(*obj).edage[i][j]);
        }
        printf("\r\n");
    }    
}

void Covert_Tmp_Table(GRAPH obj)
{
    if(tmp_table != NULL)
        free(tmp_table);
    tmp_table = (int**)malloc(sizeof(int*)*obj.vernum);
    for(int i=0;i<obj.vernum;i++)
        tmp_table[i] = (int*)malloc(sizeof(int)*obj.vernum);
    // [暂存临接表]
    for(int i=0;i<obj.vernum;i++)
    for(int j=0;j<obj.vernum;j++)
       tmp_table[i][j] = obj.edage[i][j];
}

void View_Graph_By_Table(GRAPH obj,int **table)
{
    for(int i=0;i<obj.vernum;i++)
    {
        for(int j=0;j<obj.vernum;j++)
        {
            printf("%2d",obj.edage[i][j]);
        }
        printf("\r\n");
    }
}

void DFS(GRAPH obj,int sver)
{
    for(int j=0;j<obj.vernum;j++)
        tmp_table[j][sver] = 0; 
    for(int i=0;i<obj.vernum;i++)
    {
        if(tmp_table[sver][i] != 0)
        {
            printf("[now:%d] -> [dst:%d]\r\n",sver,i);
            DFS(obj,i);
        }
    }
    printf("turn back!\r\n"); 
}

void BFS(GRAPH obj,int sver)
{
    int actver = 0;
    int nextver[64];
    for(int j=0;j<obj.vernum;j++)
         tmp_table[j][sver] = 0; 
    for(int i=0;i<obj.vernum;i++)
    {
        if(tmp_table[sver][i] != 0)
        {
            nextver[actver] = i;
            actver++;
            printf("[now:%d] -> [dst:%d]\r\n",sver,i);
            for(int j=0;j<obj.vernum;j++)
                tmp_table[j][i] = 0; 
        }
    }
    for(int i=0;i<actver;i++)
        BFS(obj,nextver[i]);
}

#define UnLimit 100
int mypow(int x)     //base = 2
{
    int ret = 1;
    for(int i=0;i<x;i++)
        ret*=2;
    return ret;
}
int flag_judge(int x,int *flag)
{
    int ret = 1;
    for(int i=0;i<x;i++)
    {
        ret *= flag[i];
    }
    return ret;
}


void DjTsl(GRAPH obj,int vertex)
{
    int shortest[64];
    //unsigned int flag = (1<<vertex); //0x01
    unsigned int flag[64] = {0};
    int min = 0;
    flag[vertex] = 1;
    memset(shortest,UnLimit,sizeof(int)*64);

    // while(!flag_judge(obj.vernum,flag))
    // {
        for(int i=0;i<obj.vernum;i++)
        {
            int route[64] = {0};
            for(int k=0;k<obj.vernum;k++)
            { 
                route[k] = obj.edage[i][k];    
                if( (i != vertex) && flag[i]) 
                    route[k] += shortest[i];
                if(shortest[k]>route[k])
                    shortest[k] = route[k];
                //printf("now:%4d pre:%4d ",shortest[k],route[k]);
            }
            //printf("\r\n");
            /*
            *   从vertex出发经过由贪心算法求得的k
            *   再从k顶点出发更新vertex各个节点的距离
            *   直到算法计算出vertex到所有定点的最短路径
            */
            int tmp = 100;
            for(int j=0;j<obj.vernum;j++)
            {
                if( !flag[j] ) // 不属于已知路径才进行贪心算法得出下一个纳入已知的节点
                {
                    if(tmp > shortest[j])
                    {
                        tmp = shortest[j];
                        min = j;
                    }
                }
            }
            
            flag[min] = 1;
            min = 0;
            // for(int n=0;n<obj.vernum;n++)
            //     printf("%2d",flag[n]);
            // printf("\r\n");
        }
        shortest[vertex] = 0;   //出发点到本身的最短距离为零
    // }
    for(int i=0;i<obj.vernum;i++)
        printf("[myvertex<%d> to(2) verte<%d> shortest --- [%d]]\r\n",vertex,i,shortest[i]);
}