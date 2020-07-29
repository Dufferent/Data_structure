#ifndef __STACK_H
#define __STACK_H

/* operation state */
#define Status       int

#define OKAY         0
#define TURE         1
#define FALSE       -1
#define OVERFLOW    -2
#define INCREABLE   -3


/* data element type */
#define ELEMENT_TYPE char
#define Quiet_SIZE    10

/* data structure */
typedef struct{
    ELEMENT_TYPE *data;
    //ELEMENT_TYPE *head;
    //ELEMENT_TYPE *fear;
    unsigned int head;
    unsigned int fear;
    unsigned int room;
}Queue;

/* op */
Status Queue_Init(Queue *obj,unsigned int size);
Status Insert_Queue(Queue *obj,ELEMENT_TYPE data);
ELEMENT_TYPE Out_Queue(Queue *obj);

#endif