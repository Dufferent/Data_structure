#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct heap{
	int *head;
	int heapmaxsize;
};

int array[10] = {8,1,7,10,23,6,4,2,3,11};

void Creat_Heap(struct heap *obj,int heap_size,int *array)
{
	int *op;
	obj->head = (int *)malloc(sizeof(struct heap)*(heap_size+1));
	obj->heapmaxsize = heap_size;
	op = obj->head;
	(*op) = 0;			//堆顶初始化为0
	op++;				//跳过堆顶
	for(int i=0;i<heap_size;i++)
	{
		(*op) = array[i];
		op++;
	}
}

void Max_Heap_Init(struct heap *obj,int index)
{
	int son_l,son_r;
	if(index <= obj->heapmaxsize)
	{
		Max_Heap_Init(obj,index+1);
		son_l  = index*2;
		son_r  = index*2 + 1;
		obj->head[0] = obj->head[index];
		if(son_l <= obj->heapmaxsize)
			if(obj->head[0] < obj->head[son_l])
			{
				obj->head[0] = obj->head[son_l];
				obj->head[son_l] = obj->head[index];
				obj->head[index] = obj->head[0];
				Max_Heap_Init(obj,son_l);
				obj->head[0] = obj->head[index];
			}
		if(son_r <= obj->heapmaxsize)
			if(obj->head[0] < obj->head[son_r])
			{
				obj->head[0] = obj->head[son_r];
				obj->head[son_r] = obj->head[index];
				obj->head[index] = obj->head[0];
				Max_Heap_Init(obj,son_r);
				obj->head[0] = obj->head[index];
			}
	}
}

void Min_Heap_Init(struct heap *obj,int index)
{
	int son_l,son_r;
	if(index <= obj->heapmaxsize)
	{
		Min_Heap_Init(obj,index+1);
		son_l  = index*2;
		son_r  = index*2 + 1;
		obj->head[0] = obj->head[index];
		if(son_l <= obj->heapmaxsize)
			if(obj->head[0] > obj->head[son_l])
			{
				obj->head[0] = obj->head[son_l];
				obj->head[son_l] = obj->head[index];
				obj->head[index] = obj->head[0];
				Min_Heap_Init(obj,son_l);
				obj->head[0] = obj->head[index];
			}
		if(son_r <= obj->heapmaxsize)
			if(obj->head[0] > obj->head[son_r])
			{
				obj->head[0] = obj->head[son_r];
				obj->head[son_r] = obj->head[index];
				obj->head[index] = obj->head[0];
				Min_Heap_Init(obj,son_r);
				obj->head[0] = obj->head[index];
			}
	}
}

void Show_Heap(struct heap obj)
{
	printf("[heap]---: ");
	for(int i=1;i<=obj.heapmaxsize;i++)
		printf("%3d",obj.head[i]);
	printf("\r\n");
}

int main(int argc,char** argv)
{
	struct heap my_heap;
	Creat_Heap(&my_heap,10,array);
	Show_Heap(my_heap);
	Max_Heap_Init(&my_heap,1);
	Show_Heap(my_heap);
	Min_Heap_Init(&my_heap,1);
	Show_Heap(my_heap);
	return 0;
}
