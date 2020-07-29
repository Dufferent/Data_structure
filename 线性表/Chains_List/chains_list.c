#include "stdio.h"
#include "stdlib.h"
#include "fcntl.h"
#include "unistd.h"
#include "sys/types.h"
#include "string.h"
/* order list */
#include <chains_list.h>

//链表初始化
Status Chains_List_Init(LNode *obj,unsigned int size)
{
    //op pointer
    LNode v;
    //1.创建头结点
    (*obj) = (LNode)malloc(sizeof(List));
    if( (*obj) == NULL)
    {
        printf("List Allocated failed!\r\n");
        return -OVERFLOW;
    }
    //2.初始化头结点
    v = (*obj);
    v->val   = 0;
    v->index = 1;
    if(size > 0)
    {
        v->size = size;
        for(int i=0;i<v->size-1;i++)
        {
            LNode new;
            new = (LNode)malloc(sizeof(List));
            new->val   = 0;
            new->size  = size;
            new->index = i+2;
            new->Next  = NULL;

            v->Next = new;
            v       = v->Next;
        }
    }
    else
    {
        v->size = Quiet_LIST_SIZE;
        for(int i=0;i<v->size;i++)
        {
            LNode new;
            new = (LNode)malloc(sizeof(List));
            new->val   = 0;
            new->size  = size;
            new->index = i+2;
            new->Next  = NULL;

            v->Next = new;
            v       = v->Next;
        }
    }
    return OKAY;
}

//插入
Status Insert_Chains_List(LNode *obj,unsigned int index,ELEMENT_TYPE val)
{
    //op pointer
    LNode v;
    LNode op;
    v  = (*obj);
    op = (*obj);
    if(v == NULL)
    { 
        printf("List is NULL!\r\n");
        return -OVERFLOW;
    }

    //1.判断索引在链表的位置
    if( (index < v->size) && (index > 0) )
    {
        //索引未越界
        while(v->index != index)
        {
            //找到对应的索引节点
            v = v->Next;
        }
        v->val = val;
        return OKAY;
    }
    else if(index > v->size)
    {
        unsigned int reduce = index - v->size;
        while(v->Next != NULL)
        {
            //切换指针到链表末尾
            v=v->Next;
        }
        for(int i=0;i<reduce;i++)
        {
            LNode new;
            new = (LNode)malloc(sizeof(List));
            new->val   = 0;
            new->size  = v->size;
            new->index = v->index+1;
            new->Next  = NULL;

            v->Next = new;
            v       = v->Next;
        }
        //到了给定节点
        v->val = val;
        //更新链表size
        while(op->Next != NULL)
        {
            op->size += reduce;
            op = op->Next;
            if(op->Next == NULL)
                op->size += reduce;
        }
    }
    else
    {
        printf("index has to be unsigned int type!\r\n");
        return INCREABLE;
    }
}

//查找
//1.索引查找
ELEMENT_TYPE Look_Index_List(LNode obj,unsigned int index)
{
    if(obj == NULL)
    { 
        printf("List is NULL!\r\n");
        return -OVERFLOW;
    }
    while(obj->Next != NULL)
    {
        if(obj->index == index)
        {
            return obj->val;
        }
        obj = obj->Next;
        if(obj->Next == NULL)
        {
            if(obj->index == index)
            {
                return obj->val;
            }
        }
    }
    return FALSE;
}
//2.按值查找
int Look_Val_List(LNode obj,ELEMENT_TYPE val)
{
    if(obj == NULL)
    { 
        printf("List is NULL!\r\n");
        return -OVERFLOW;
    }
    while(obj->Next != NULL)
    {
        if(obj->val == val)
        {
            return obj->index;
        }
        obj = obj->Next;
        if(obj->Next == NULL)
        {
            if(obj->val == val)
            {
                return obj->index;
            }
        }
    }
    return FALSE;
}

//删除
//1.删值
//1.1按索引删
Status Delete_Index(LNode *obj,unsigned int index)
{
    //op poniter 
    LNode op;
    op = (*obj);
    if(op == NULL)
    { 
        printf("List is NULL!\r\n");
        return -OVERFLOW;
    }
    Insert_Chains_List(&op,index,0);

    return OKAY;
}
//1.2按值删除
Status Delete_Val(LNode *obj,ELEMENT_TYPE val)
{
    //op poniter 
    LNode op;
    op = (*obj);
    if(op == NULL)
    { 
        printf("List is NULL!\r\n");
        return -OVERFLOW;
    }
    int ret = Look_Val_List(op,val);//查找索引号
    if(ret == -1)
    {
        printf("Look for val failed!\r\n");
        return FALSE;
    }
    Insert_Chains_List(&op,ret,0);

    return OKAY;
}

//2.删除节点
//2.1按索引删
Status Delete_Node(LNode *obj,unsigned int index)
{
    LNode op;
    LNode tp;
    op = (*obj);
    tp = (*obj);
    if(op == NULL)
    { 
        printf("List is NULL!\r\n");
        return -OVERFLOW;
    }
    //assert
    if( (index > op->size) || (index <= 0) )
    {
        return INCREABLE;
    }
    //找到对应节点
    if(op->index != index)
    {
        //不是头结点
        while(op->Next != NULL)
        {
            if(op->Next->index == index)
            {
                break;
            }
            op = op->Next;
        }
    }
    else
    {
        //是头结点
        tp = tp->Next;
        (*obj) = (*obj)->Next;
        op->Next = NULL;
        free(op);

        //更新链表size
        while(tp->Next != NULL)
        {
            if(tp->index > index)
            {
                tp->index -= 1;
            }
            tp->size -= 1;
            tp = tp->Next;
            if(tp->Next == NULL)
            {
                if(tp->index > index)
                    tp->index -= 1;
                tp->size -=1;
            }
        }

        return OKAY;
    }
    
    //不是头结点，断链操作
    LNode v;
    v = op->Next;
    op->Next = op->Next->Next;
    v->Next = NULL;
    free(v);
    //更新链表size
    while(tp->Next != NULL)
    {
        if(tp->index > index)
        {
            tp->index -= 1;
        }
        tp->size -= 1;
        tp = tp->Next;
        if(tp->Next == NULL)
        {
            if(tp->index > index)
                tp->index -= 1;
            tp->size -= 1;
        }
    }
    return OKAY;
}
//2.2按值删除
Status Delete_Node_V(LNode *obj,ELEMENT_TYPE val)
{
    int index = Look_Val_List((*obj),val);
    Delete_Node(obj,index);
    return OKAY;
}

//遍历
Status View_List(LNode obj)
{
    while(obj->Next != NULL)
    {
        printf("%d:%-4c",obj->index,obj->val);
        obj = obj->Next;
        if(obj->Next == NULL)
        {
            printf("%d:%-4c\r\n",obj->index,obj->val);
        }
    }
    return OKAY;
}