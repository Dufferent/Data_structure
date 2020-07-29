#include "stdio.h"
#include "stdlib.h"
#include "fcntl.h"
#include "unistd.h"
#include "sys/types.h"
#include "string.h"
#include "btree.h"

BNode BTree_New_Node(ELEMENT_TYPE val)
{
    BNode new;
    new = (BTree*)malloc(sizeof(BTree));
    if(new == NULL)
    {
        printf("allocated failed!\r\n");
        return NULL;
    }
    new->data = val;
    new->lchild = NULL;
    new->rchild = NULL;
    return new;
}
//先序初始化
BNode BTree_Order_Init(BNode *obj)
{
    //操作节点
    BNode op;
    op = *obj;
    char val = *ccmd;

    if( (*ccmd != '_') && (*ccmd != '#'))
    {
        op = BTree_New_Node(0);
        ccmd++;
        op->data   = val; 
        op->lchild = BTree_Order_Init(&op->lchild);
        op->rchild = BTree_Order_Init(&op->rchild);
        return op;
    }
    else
    {
        ccmd++;
        return NULL;
    }
}
//中序初始化
BNode BTree_Mid_Init(BNode *obj)
{
    //操作节点
    BNode op;
    char val = *ccmd;
    op = *obj;

    if( (*ccmd != '#') && (*ccmd != '_') )
    {
        ccmd++;//abc__d__ef___#
        op = BTree_New_Node(0);
        op->lchild = BTree_Mid_Init(&op->lchild);
        op->data   = val;
        op->rchild = BTree_Mid_Init(&op->rchild);
        return op;
    }
    else
    {
        ccmd++;
        return NULL;
    }
}

//后序初始化
BNode BTree_Last_Init(BNode *obj)
{
    //操作节点
    BNode op;
    op = *obj;
    char val=*ccmd;
    
    if( (*ccmd != '_') && (*ccmd != '#'))
    {
        op = BTree_New_Node(0);
        ccmd++;
        op->lchild = BTree_Last_Init(&op->lchild);
        op->rchild = BTree_Last_Init(&op->rchild);
        op->data = val;
        return op;
    }
    else
    {
        ccmd++;
        return NULL;
    }
}
//##########################################################
//先序初遍历
void BTree_Order_Vist(BNode obj)
{
    if(obj)
    {
        printf("%c",obj->data);
        if(obj->lchild)
            BTree_Order_Vist(obj->lchild);
        if(obj->rchild)
            BTree_Order_Vist(obj->rchild);
    }
}

//中序遍历
void BTree_Mid_Vist(BNode obj)
{
    if(obj)
    {
        if(obj->lchild)
            BTree_Mid_Vist(obj->lchild);
        printf("%c",obj->data);
        if(obj->rchild)
            BTree_Mid_Vist(obj->rchild);
    }
}

//后序遍历
void BTree_Last_Vist(BNode obj)
{
    if(obj)
    {
        if(obj->lchild)
            BTree_Last_Vist(obj->lchild);
        if(obj->rchild)
            BTree_Last_Vist(obj->rchild);
        printf("%c",obj->data);
    }
}











