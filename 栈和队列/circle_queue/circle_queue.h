#ifndef __CIRCLE_QUEUE_H
#define __CIRCLE_QUEUE_H

#define ElemType int 

/* structors */
typedef struct {
    ElemType *dfiled;
    int rear;
    int front;
    int remain;
    int maxsize;
}CirQueue;

//op
void CQ_Init(CirQueue *obj,int size);
int Is_Empty(CirQueue obj);
int Is_Full(CirQueue obj);
int Get_Restore(CirQueue obj);
void CQ_In(CirQueue *obj,ElemType val);
ElemType CQ_Out(CirQueue *obj);


#endif