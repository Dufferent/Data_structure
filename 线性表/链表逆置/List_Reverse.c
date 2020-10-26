#include "stdio.h"
#include "stdlib.h"

typedef struct list{
	int data_field;
	struct list *next;
}*LNode,List;

void New_List(LNode *obj)
{
	LNode head = (LNode)malloc(sizeof(List));
	head->next = NULL;
	head->data_field = 0;
	(*obj) = head;
}

void List_Init(LNode *obj,int nums)
{
	LNode op = (*obj);
	for(int i=1;i<=nums;i++)
	{
			LNode new_node = (LNode)malloc(sizeof(List));
			new_node->next = NULL;
			new_node->data_field = i;
			op->next = new_node;
			op = op->next;
	}
}

void Vist_List(LNode obj)
{
	printf("%2d ",obj->data_field);
	if(obj->next != NULL)
		Vist_List(obj->next);
}

// h* -> L1 -> L2 -> L3 -> L4 -> ... ... -> Ln
// NULL <- h* <- L1 ...
// ... ...
// 

LNode List_Reverse(LNode *obj)
{
	LNode pre,cur,next;
	pre = NULL;
	cur = (*obj);
	next = cur->next;
	(*obj)->next = NULL;
	while(next != NULL)
	{
		pre = cur;
		cur = next;
		next = cur->next;
		cur->next = pre;
	}
	return cur;
}

int main(int argc,char** argv)
{
	LNode mylist;
	LNode ret;
	New_List(&mylist);
	List_Init(&mylist,4);
	Vist_List(mylist);
	printf("\r\n");
	ret = List_Reverse(&mylist);
	Vist_List(ret);
	return 0;
}