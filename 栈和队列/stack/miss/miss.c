#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "unistd.h"
#include "miss.h"

//栈
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
        *(obj->data) = (struct Route){
            (unsigned int)0,
            (unsigned int)0,
        };
        return ret;
    }
    else
    {
        printf("Stack is empty now\r\n");
        return (struct Route){0,0};
    }
}

struct Route my_route={
    .pos = pos(1,1),//起点
    .dir = Right,   //向右
    .last_dir = UNKNOW,//上次方向
};

Status Missing_route(void)
{
    unsigned int graph[10][10] = {
        {1,1,1,1,1,1,1,1,1,1},//0
        {1,0,0,1,0,0,0,1,0,1},//1
        {1,0,0,1,0,0,0,1,0,1},//2
        {1,0,0,0,0,1,1,0,0,1},//3
        {1,0,1,1,1,0,0,0,0,1},//4
        {1,0,0,0,1,0,0,0,0,1},//5
        {1,0,1,0,0,0,1,0,0,1},//6  
        {1,0,1,1,1,0,1,1,0,1},//7
        {1,1,0,0,0,0,0,0,0,1},//8
        {1,1,1,1,1,1,1,1,1,1},//9
    //   0 1 2 3 4 5 6 7 8 9  
    };
    STACK my_stack;
    Stack_Init(&my_stack,256);
    //出口
    unsigned char out = pos(8,8);
    //起点入栈
    Stack_Push(&my_stack,my_route);
    graph[my_route.pos/10][my_route.pos%10] = 1;//走过

    //一直找出口
    while(my_route.pos != out)
    {
        switch (my_route.dir)
        {
            case Right:{
                            if(my_route.last_dir != Left)
                            {
                                if(graph[my_route.pos/10][my_route.pos%10+1])//向右走不通
                                {
                                    my_route.dir = Down;
                                }
                                else
                                {
                                    graph[my_route.pos/10][my_route.pos%10] = 2;//走过
                                    my_route.pos += 1;//向右走一步
                                    
                                    my_route.last_dir = Right;
                                    Stack_Push(&my_stack,my_route);
                                }
                            }
                            else
                            {
                                my_route.dir = Down;
                            }
                        }break;
            case Down:{
                            if(my_route.last_dir != Up)
                            {
                                if(graph[my_route.pos/10+1][my_route.pos%10])//向下走不通
                                {
                                    my_route.dir = Left;
                                }
                                else
                                {
                                    graph[my_route.pos/10][my_route.pos%10] = 2;//走过
                                    my_route.pos += 10;//向下走一步
                                    Stack_Push(&my_stack,my_route);
                                    my_route.dir = Right;//重置状态机
                                    my_route.last_dir = Down;
                                }
                            }
                            else
                            {
                                 my_route.dir = Left;
                            }
                        }break;
            case Left:{
                            if(my_route.last_dir != Right)
                            {
                                if(graph[my_route.pos/10][my_route.pos%10-1])//向左走不通
                                {
                                    my_route.dir = Up;
                                }
                                else
                                {
                                    graph[my_route.pos/10][my_route.pos%10] = 2;//走过
                                    my_route.pos -= 1;//向左走一步
                                    Stack_Push(&my_stack,my_route);
                                    
                                    my_route.dir = Right;
                                    my_route.last_dir = Left;
                                }
                            }
                            else
                            {
                                my_route.dir = Up;
                            }
                        }break;
            case Up:{       
                            if(my_route.last_dir != Down)
                            {
                                if(graph[my_route.pos/10-1][my_route.pos%10])//向上走不通
                                {
                                    my_route.dir = UNKNOW;
                                }
                                else
                                {
                                    graph[my_route.pos/10][my_route.pos%10] = 2;//走过
                                    my_route.pos -= 10;//向上走一步
                                    Stack_Push(&my_stack,my_route);
                                    
                                    my_route.dir = Right;
                                    my_route.last_dir = Up;
                                }
                            }
                            else
                            {
                                my_route.dir = UNKNOW;
                            }
                        }break;
            default:{
                        graph[my_route.pos/10][my_route.pos%10] = 1;//死路不走了
                        my_route = Stack_Pop(&my_stack);
                        my_route.dir++;
            }
            break;
        }
        usleep(500*1000);
        printf("now pos:(%d,%d)\tnow dir:%d\r\n",my_route.pos/10,my_route.pos%10,my_route.dir);
    }
    printf("SUCCESSFUL!\r\n");
    for(int y=0;y<10;y++)
    {
        for(int x=0;x<10;x++)
        {
            printf("%-2d",graph[y][x]);
        }
        printf("\n");
    }


    return OKAY;
}

int main(void)
{
    Missing_route();
    return 0;
}