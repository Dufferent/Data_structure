#ifndef __ORDER_LIST_H
#define __ORDER_LIST_H

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
    ELEMENT_TYPE *list;
    unsigned int list_size;
}Order_List;

/* op */
Status Order_List_Init(Order_List *obj,unsigned int size);
Status Insert_Element(Order_List *obj,unsigned int position,ELEMENT_TYPE val);
Status Delete_Element(Order_List *obj,unsigned int position);
Status Look_Element(Order_List *obj,unsigned int position);

#endif