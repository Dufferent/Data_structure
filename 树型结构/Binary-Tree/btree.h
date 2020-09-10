#ifndef __BTREE_H
#define __BTREE_H

/* operation state */
#define Status       int

#define OKAY         0
#define TURE         1
#define FALSE       -1
#define OVERFLOW    -2
#define INCREABLE   -3

/* data element type */
#define ELEMENT_TYPE char

/* data structure */
typedef struct bt{
    ELEMENT_TYPE data;
    struct bt *rchild;
    struct bt *lchild;
}BTree,*BNode;

/* op */
extern char* ccmd;

BNode BTree_New_Node(ELEMENT_TYPE val);
BNode BTree_Order_Init(BNode *obj);
void BTree_Order_Vist(BNode obj);
BNode BTree_Mid_Init(BNode *obj);
void BTree_Mid_Vist(BNode obj);
BNode BTree_Last_Init(BNode *obj);
void BTree_Last_Vist(BNode obj);

void BTree_Index(BNode *obj);
int BTree_Change_RL(BNode *obj);
#endif
