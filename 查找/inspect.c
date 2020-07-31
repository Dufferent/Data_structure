#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "fcntl.h"
#include "sys/types.h"
#include "string.h"
#include <inspect.h>
int Get_Len(Element_Type *array)
{
    int ct = 0;

    switch(sizeof(Element_Type))
    {
        case 1:return (int)(strlen((char*)array));break;
        default:while(*array != 65536){
            array++;
            ct++;
        };return (ct);break;
    }
}
void ARRAY_SHOW(Element_Type *array)
{
    for(int i=0;i<Get_Len(array);i++)
    {
        switch(sizeof(Element_Type))
        {
            case 1:printf("%4c",array[i]);break;
            default:printf("%4d",array[i]);break;
        }
    }
    printf("\r\n");
}
/* ways */
//1.静态查找表
int Inspect_Directly(Element_Type *array,Element_Type val)
{
    for(int i=0;i<Get_Len(array);i++)
        if(array[i] == val)return i;
    return -1;
}
//1.1有序查找
int Sort_Inspect(Element_Type *array,Element_Type val,unsigned int dir)
{
    for(int i=0;i<Get_Len(array);i++)
    {
        if(array[i] == val)return i;
        if(dir)
        {
            if( val < array[i])
                return -1;
        }
        else
        {
            if( val > array[i])
                return -1;
        }
    }
    return -1;
}
//1.2折半查找
int Half_Inspect(Element_Type *array,unsigned int s,unsigned int e,Element_Type val,unsigned int dir)
{
    int len = e+s;
    len /= 2;

    //printf("start:%d\tend:%d\tlen:%d\r\n",s,e,len);

    if(e -s == 1)
        return -1;
    
    if(dir)
    {
        if(len)
        {
            if(val > array[len])
            {
                Half_Inspect(array,len,e,val,dir);
            }
            else if(val == array[len])
            {
                return len;
            }
            else
            {
                Half_Inspect(array,s,len,val,dir);
            }
        }
        else
        {
            if(val == array[len])
                return len;
            else
                return -1;
        }
    }
    else
    {
        if(len)
        {
            if(val > array[len])
            {
                Half_Inspect(array,s,len-1,val,dir);
            }
            else if(val == array[len])
            {
                return len;
            }
            else
            {
                Half_Inspect(array,len+1,e,val,dir);
            }
        }
        else
        {
            if(val == array[len])
                return len;
            else
                return -1;
        }
    }
}
//2.二叉搜索树
BNode New_BNode(Tree_Data_Type data)
{
    BNode new;
    new = (BNode)malloc(sizeof(Btree));
    if(data>0)
        new->data = data;
    else
        new->data = 0;

    new->lchild = NULL;
    new->rchild = NULL;
    return new;
}
//中序创建二叉搜索树
void Input_buf(Tree_Data_Type *p)
{ 
    do{
        scanf("%d",p);
        p++;
    }while((*(p-1)) != Tree_End);
}
void Show_buf(Tree_Data_Type *p)
{
    while(*p != Tree_End)
    {
        printf("%2d",*p);
        p++;
    }
    printf("\r\n");
}
BNode Creat_Inspect_Tree(BNode *obj)
{
    Tree_Data_Type transient;
    BNode op = *obj;
    transient = *str;
    //6421_(-1)_(-1)3__5__7__
    /*
     *           6
     *          /\
     *         4  7  
     *        /\
     *       2  5
     *      /\
     *     1  3
     */

    if( (*(str) != _) && (*(str) != Tree_End) )
    {
        str += 1;
        op = New_BNode(transient);
        //printf("transient:%d\tnext_str:%d\r\n",transient,*str);
        op->lchild =  Creat_Inspect_Tree(&op->lchild);
        op->rchild =  Creat_Inspect_Tree(&op->rchild);
        return op;
    }
    else
    {
        str++;
        return NULL;
    }
}

void Vist_Inspect_Tree(BNode obj)
{
    if(obj->lchild)
        Vist_Inspect_Tree(obj->lchild);
    printf("%2d",obj->data);
    if(obj->rchild)
        Vist_Inspect_Tree(obj->rchild);
}

BNode Inspect_The_Tree(BNode obj,Tree_Data_Type val)
{
    if(val > obj->data)
        Inspect_The_Tree(obj->rchild,val);
    else if(val == obj->data)
        return obj;
    else
        Inspect_The_Tree(obj->lchild,val);   
}





