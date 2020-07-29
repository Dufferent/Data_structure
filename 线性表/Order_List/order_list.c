#include "stdio.h"
#include "stdlib.h"
#include "fcntl.h"
#include "unistd.h"
#include "sys/types.h"
#include "string.h"
/* order list */
#include <order_list.h>

//顺序表初始化
Status Order_List_Init(Order_List *obj,unsigned int size)
{
    if(size > 0)
    {
        obj->list_size = size;
        obj->list = (ELEMENT_TYPE*)malloc(obj->list_size*sizeof(ELEMENT_TYPE));
        memset(obj->list,0,sizeof(ELEMENT_TYPE)*obj->list_size);
        return OKAY;
    }
    else
    {
        obj->list_size = Quiet_LIST_SIZE;
        obj->list = (ELEMENT_TYPE*)malloc(obj->list_size*sizeof(ELEMENT_TYPE));
        memset(obj->list,0,sizeof(ELEMENT_TYPE)*obj->list_size);
        return OKAY;
    }
}

//增
Status Insert_Element(Order_List *obj,unsigned int position,ELEMENT_TYPE val)
{
    if(obj->list != NULL)
    {
        obj->list[position] = val;
        return OKAY;
    }
    else
    {
        return INCREABLE;
    }
}

//删
Status Delete_Element(Order_List *obj,unsigned int position)
{
    if(obj->list != NULL)
    {
        obj->list[position] = 0;
        return OKAY;
    }
    else
    {
        return INCREABLE;
    }
}

//查
Status Look_Element(Order_List *obj,unsigned int position)
{
    if(obj->list != NULL)
    {
        printf("list[%d] is :%c\r\n",position,obj->list[position]);
        return OKAY;
    }
    else
    {
        return INCREABLE;
    }
}