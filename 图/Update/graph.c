#include "stdio.h"
#include "stdlib.h"
#include "sys/types.h"
#include "fcntl.h"
#include "unistd.h"
#include "string.h"

#define False 0
#define True  1

typedef struct{
    //int *vertex; //顶点
    int **edage; //边
    int vernums; 
    int edanums;
    int **table; //表
}graph;

int Graph_Init(graph *obj)
{
    obj->vernums = 0;
    obj->edanums = 0;
    printf("请输入边和顶点的数目...\r\n");
    printf("EG：5,6[回车]\r\n");
    scanf("%d,%d",&obj->vernums,&obj->edanums);
    if( !(obj->edanums) || !(obj->vernums) )return -1;
    printf("请输入边：EG：[source]%s,[wt]%s.[dest]%s\r\n","%d","%d","%d");
    //alloc
    //obj->vertex = (int*)malloc(sizeof(int)*obj->vernums);
    obj->edage  = (int**)malloc(sizeof(int*)*obj->vernums);
    obj->table  = (int**)malloc(sizeof(int*)*obj->vernums);
    for(int i=0;i<obj->vernums;i++)
        obj->edage[i] = (int*)malloc(sizeof(int)*obj->vernums);
    for(int i=0;i<obj->vernums;i++)
        obj->table[i] = (int*)malloc(sizeof(int)*obj->vernums);    
    for(int i=0;i<obj->edanums;i++)
    {
        int source,wt,dest;
        scanf("%d,%d,%d",&source,&wt,&dest);
        obj->edage[source][dest] = wt;
        obj->table[source][dest] = wt;
    }
    printf("邻接矩阵...\r\n");
    for(int i=0;i<obj->vernums;i++)
    {
        for(int j=0;j<obj->vernums;j++)
        {
            printf(" %d ",obj->table[i][j]);
        }
        printf("\r\n");
    }
    return 0;
}

void recovert(graph obj,int **table)
{
    for(int i=0;i<obj.vernums;i++)
    for(int j=0;j<obj.vernums;j++)
        table[i][j] = obj.edage[i][j];    
}

int fjudge(graph obj,int *flag)
{
    for(int i=0;i<obj.vernums;i++)
        if(flag[i]==0)
            return False;
    return True;
}

#define MAXINT 65536
//节点索引默认0开始编号
int Djstl(graph obj,int sver)
{
    int *flag = (int*)malloc(sizeof(int)*obj.vernums);
    memset(flag,False,obj.vernums);
    int **shorest = (int**)malloc(sizeof(int*)*obj.vernums);
    for(int i=0;i<obj.vernums;i++)
        shorest[i] = (int*)malloc(sizeof(int)*obj.vernums);
    for(int i=0;i<obj.vernums;i++)
        shorest[sver][i] = MAXINT;
    for(int i=0;i<obj.vernums;i++)
    for(int j=0;j<obj.vernums;j++)
        if(obj.table[i][j] == 0)obj.table[i][j] = MAXINT;

    flag[sver] = True;  //出发节点纳入路径规划
    shorest[sver][sver] = 0;
    int curver = sver;

    //djstl start
    while(!fjudge(obj,flag))
    {
        //从开始节点出发
        for(int i=0;i<obj.vernums;i++)
        {
            if( obj.table[curver][i]<MAXINT )//可以达到
            {
                if(shorest[sver][i]  > obj.table[curver][i] + shorest[sver][curver] )
                    shorest[sver][i] = obj.table[curver][i] + shorest[sver][curver];
            }
        }
        // for(int i=0;i<obj.vernums;i++)
        //     printf("flag[%d] : %d \r\n",i,flag[i]);
        // for(int i=0;i<obj.vernums;i++)
        //     printf("sver to dest[%d] shortest route: %d \r\n",i,shorest[sver][i]);
        //将最短路程的节点纳入规划
        int min = MAXINT;
        int index = -1;
        for(int i=0;i<obj.vernums;i++)
        {
            if( (min > shorest[sver][i])&&(!flag[i]) )
            {
                min = shorest[sver][i];
                index = i;
            }
        }
        if(index==-1)return -1;
        flag[index] = True;  //出发节点纳入路径规划
        curver = index;
    }
    for(int i=0;i<obj.vernums;i++)
        printf("sver to dest[%d] shortest route: %d \r\n",i,shorest[sver][i]);
    return 0;
}

int main(int argc,char** argv)
{
    graph mg;
    int ret = Graph_Init(&mg);
    if(ret < 0)
    {
        printf("图初始化错误！\r\n");
        exit(-1);
    }
    ret = Djstl(mg,0);
    if(ret < 0)
    {
        printf("算法出错！\r\n");
        exit(-1);
    }
    return 0;
}

