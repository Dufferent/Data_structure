#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct{
	int data[5];
	int *top;
	int *base;
	int count;
}Stack;

typedef struct{
	int data[512];
	int rear;
	int head;
}Queue;

void Stack_Init(Stack *obj)
{
	memset(obj->data,0,sizeof(int)*5);
	obj->base = &obj->data[0];
	obj->top  = &obj->data[0];
	obj->count = 0;
}

void Push(Stack *obj,int val)
{
	if(obj->count < 5)
	{
		*(obj->top) = val;
		obj->top += 1;
		(obj->count)++;
	}
	else
		printf("FULL Stack!\r\n");
}
int Pop(Stack *obj)
{
	int ret;
	if(obj->top != obj->base)
	{
		obj->top -= 1;
		(obj->count)--;
		ret = *(obj->top);
		*(obj->top) = 0;
		return ret;
	}
	else
	{
		printf("NULL Stack!\r\n");
		return -1;
	}
}

void Queue_Init(Queue *obj)
{
	memset(obj->data,0,sizeof(int)*512);
	obj->rear = 0;
	obj->head = 0;
}

void InQueue(Queue *obj,int val)
{
	if(obj->head < 512)
	{
		obj->data[obj->head] = val;
		obj->head++;
	}
	else
		printf("FULL Queue!\r\n");
}

int DeQueue(Queue *obj)
{
	int ret;
	if(obj->rear != obj->head)
	{
		ret = obj->data[obj->rear];
		obj->data[obj->rear] = 0;
		obj->rear++;
		return ret;
	}
	else
	{
		obj->rear = 0;
		obj->head = 0;
		printf("NULL Queue!\r\n");
		return (-1);
	}
}
int opnums = 0;
int fun(Queue *to,Stack *src,int num)
{
	int ret;
	//int n = num-1;
	//while(ret != -1)
	//{
	ret = Pop(src);
	if(ret != -1)
	{
		InQueue(to,ret);
		for(int i=0;i<num-1;i++)
		{
			InQueue(to,DeQueue(to));
			opnums += 2;
		}
		//n++;
		opnums += 2;
		fun(to,src,num+1);
	}
	//}
}

void Vist_Queue(Queue obj)
{
	for(int i=0;i<512;i++)
	{
		if(obj.data[i] > 0)
			printf("Queue<%d> : %2c\r\n",i,((obj.data[i] == 1)?('a'):('b')));
	}
	printf("\r\n");
}

void main()
{
	Stack mystack;
	Queue myqueue;
	Stack_Init(&mystack);
	Queue_Init(&myqueue);
	
	for(int i=0;i<5;i++)
		Push(&mystack,1);	//stack -> a
	for(int i=0;i<5;i++)
		InQueue(&myqueue,2);//queue -> b
	
	fun(&myqueue,&mystack,5);
	Vist_Queue(myqueue);
	printf("base - op nums:%2d\r\n",opnums);
}

