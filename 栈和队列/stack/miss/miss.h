#ifndef __STACK_H
#define __STACK_H

/* operation state */
#define Status       int

#define OKAY         0
#define TURE         1
#define FALSE       -1
#define OVERFLOW    -2
#define INCREABLE   -3

//迷宫求解
#define pos(y,x) (y*10 + x)
#define Right 0
#define Left  2
#define Up    3
#define Down  1
#define UNKNOW 100

struct Route{
    unsigned int pos;
    unsigned int dir;
    unsigned int last_dir;
};

/* data element type */
#define ELEMENT_TYPE struct Route
#define Quiet_LIST_SIZE    10

/* data structure */
typedef struct{
    ELEMENT_TYPE *data;
    ELEMENT_TYPE *top;
    ELEMENT_TYPE *end;
}STACK;

/* op */
Status Stack_Init(STACK *obj,unsigned int deep);
Status Stack_Push(STACK *obj,ELEMENT_TYPE data);
ELEMENT_TYPE Stack_Pop(STACK *obj);

#endif