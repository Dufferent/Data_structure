#include "stdio.h"
#include "stdlib.h"
#include "fcntl.h"
#include "unistd.h"
#include "sys/types.h"
#include "string.h"
#include "queue.h"

/* op */
Status Queue_Init(Queue *obj,unsigned int size)
{
    obj->data = (ELEMENT_TYPE*)malloc(sizeof(ELEMENT_TYPE)*size);
    //obj->head = obj->fear = obj->data;
    obj->head = 1;
    obj->fear = 0;
    obj->room = 0;
}

//入队
Status Insert_Queue(Queue *obj,ELEMENT_TYPE data)
{
    if(obj->head != obj->fear)
    {
        //obj->head = data;
        obj->data[obj->head] = data;
        //obj->head++;
        obj->head = ((obj->head+1)%Quiet_SIZE);
    }
    else
    {
        obj->room++;
        printf("Queue is Full!\r\n");
        return OVERFLOW;
    }
    
    return OKAY;
}

//出队
ELEMENT_TYPE Out_Queue(Queue *obj)
{
    /*
    ELEMENT_TYPE ret;
    if(obj->fear != obj->head)
    {
        ELEMENT_TYPE *f;
        f = obj->fear;
        ret = *obj->fear;
        obj->fear++;
        obj->data++;
        *f = '\0';
        f = NULL;
        return ret;
    }
    else
    {
        printf("Queue is Empty!\r\n");
        return INCREABLE;
    }
    */
    ELEMENT_TYPE ret;
    if( (obj->fear != obj->head) || (obj->room > 0) )
    {
        ret = obj->data[obj->fear];
        obj->data[obj->fear] = 0;
        obj->fear = ((obj->fear+1)%Quiet_SIZE);
        if(obj->fear == 0)
            obj->room--;
        return ret;
    }
    else
    {
        printf("Queue is Empty!\r\n");
        return INCREABLE;
    }

}