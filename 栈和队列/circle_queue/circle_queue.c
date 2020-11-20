#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "sys/types.h"
#include "fcntl.h"

#include "./circle_queue.h"

/* circle queue init */
void CQ_Init(CirQueue *obj,int size)
{
    obj->maxsize = size;
    obj->dfiled  = (ElemType*)malloc(sizeof(ElemType)*size);
    memset(obj->dfiled,0,sizeof(ElemType)*obj->maxsize);
    obj->remain  = size;
    obj->front   = 0;
    obj->rear    = 0;
}
//@param::ret  1 for Out Empty
//             0 for Out UnEmpty
int Is_Empty(CirQueue obj)
{
    if(obj.remain == obj.maxsize)
    {
        return 1;
    }
    else
        return 0;
}
//@param::ret  1 for Out Full
//             0 for Out UnFull
int Is_Full(CirQueue obj)
{
    if(obj.remain == 0)
    {
        return 1;
    }
    else
        return 0;
}

int Get_Restore(CirQueue obj)
{
    return (obj.rear + obj.maxsize - obj.front)%(obj.maxsize);
}

void CQ_In(CirQueue *obj,ElemType val)
{
    if(!(Is_Full(*obj)))
    {
        obj->dfiled[obj->rear] = val;
        obj->rear = ((obj->rear + 1)%obj->maxsize);
        obj->remain--;
    }
    else
        printf("cq is full!\r\n");
}
//@param::ret val for Out successful
//             0  for Out Failed
ElemType CQ_Out(CirQueue *obj)
{
    ElemType ret;
    if(!Is_Empty(*obj))
    {
        ret = obj->dfiled[obj->front];
        obj->dfiled[obj->front] = 0;
        obj->front = (obj->front + 1)%obj->maxsize;
        obj->remain++;
    }
    else
        ret = 0;

    return ret;
}

