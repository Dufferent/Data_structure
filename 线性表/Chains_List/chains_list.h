#ifndef __CHAINS_LIST_H
#define __CHAINS_LIST_H

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
typedef struct list{
    ELEMENT_TYPE val;
    struct list *Next;
    unsigned int size;
    unsigned int index;
}*LNode,List;

/* op */
Status Chains_List_Init(LNode *obj,unsigned int size);
Status Insert_Chains_List(LNode *obj,unsigned int index,ELEMENT_TYPE val);
ELEMENT_TYPE Look_Index_List(LNode obj,unsigned int index);
int Look_Val_List(LNode obj,ELEMENT_TYPE val);

Status Delete_Index(LNode *obj,unsigned int index);
Status Delete_Val(LNode *obj,ELEMENT_TYPE val);

Status Delete_Node(LNode *obj,unsigned int index);
Status Delete_Node_V(LNode *obj,ELEMENT_TYPE val);

Status View_List(LNode obj);
#endif