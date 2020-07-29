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
ELEMENT_TYPE Get_Top(STACK obj);

#endif