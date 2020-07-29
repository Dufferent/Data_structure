#include "stdio.h"
#include "stdlib.h"
#include "fcntl.h"
#include "unistd.h"
#include "sys/types.h"
#include "string.h"
#include "stack.h"

Status Stack_Init(STACK *obj,unsigned int deep)
{
    obj->data = (ELEMENT_TYPE*)malloc(sizeof(ELEMENT_TYPE)*deep);
    memset(obj->data,0,sizeof(ELEMENT_TYPE)*deep);
    if(obj->data != NULL)
    {
        obj->data = obj->end = obj->data;
        obj->top = obj->data+(deep)*sizeof(ELEMENT_TYPE);
    }
    else
        return OVERFLOW;
}

Status Stack_Push(STACK *obj,ELEMENT_TYPE data)
{
    if(obj->data != obj->top)
    {
        *(obj->data) = data;
        obj->data++;
    }
    else
    {
        printf("Stack is full now\r\n");
        return OVERFLOW;
    }
    
    return OKAY;
}

ELEMENT_TYPE Stack_Pop(STACK *obj)
{
    ELEMENT_TYPE ret;
    if(obj->data != obj->end)
    {
        obj->data--;
        ret =  *(obj->data);
        *(obj->data) = 0;
        return ret;
    }
    else
    {
        printf("Stack is empty now\r\n");
        return OVERFLOW;
    }
}

ELEMENT_TYPE Get_Top(STACK obj)
{
    obj.data--;
    return *(obj.data);
}