#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct tree{
	char data_field;
	struct tree *lchild;
	struct tree *rchild;
}BTree,*BNode;

BNode Creat_New_Node(char val)
{
	BNode New_Node = (BNode)malloc(sizeof(BTree));
	New_Node->data_field = val;
	New_Node->lchild = NULL;
	New_Node->rchild = NULL;
	return New_Node;
}
char *cmd;
BNode PreOrder_Create_Tree(BNode *obj)
{
	/*
	if( *(cmd) != '_' && *(cmd) != '#')
	{
		printf("%c\r\n",*cmd);
		(*obj) = Creat_New_Node(*cmd);
		cmd++;
		PreOrder_Create_Tree(&(*obj)->lchild);
		PreOrder_Create_Tree(&(*obj)->rchild);
	}
	else
	{	
		(*obj) = NULL;
		printf("%c\r\n",*cmd);
		cmd++;
	}
	*/
	if( *(cmd) != '_' && *(cmd) != '#')
	{
		BNode op;
		(*obj) = Creat_New_Node(*cmd);
		op = (*obj);
		cmd++;
		op->lchild = PreOrder_Create_Tree(&op->lchild);
		op->rchild = PreOrder_Create_Tree(&op->rchild);
		return op;
	}
	else
	{	
		cmd++;
		return NULL;
	}
}

void PreOrder_Vist_Tree(BNode obj)
{
	if(obj != NULL)
		printf("%c",obj->data_field);
	if(obj->lchild != NULL)
		PreOrder_Vist_Tree(obj->lchild);
	if(obj->rchild != NULL)
		PreOrder_Vist_Tree(obj->rchild);
}

int similar_rcgn(BNode t1,BNode t2)
{
	static int unsimilar_degree = 0;
	if( (t1 == NULL && t2 != NULL ) )
		unsimilar_degree++;
	else if( (t1 != NULL && t2 == NULL ) )
		unsimilar_degree++;
	else if( (t1 == NULL && t2 == NULL ) )
		;
	else if( (t1 != NULL && t2 != NULL ) )
	{
		similar_rcgn(t1->lchild,t2->lchild);
		similar_rcgn(t1->rchild,t2->rchild);
	}
	return unsimilar_degree;
}

void main()
{
	BNode mytree;
	BNode mytree_cmp;
	int node_nums;
	printf("please input tree1 node nums!\r\n");
	scanf("%d",&node_nums);
	printf("please input node data of %d!\r\n",node_nums);
	for(int i=0;i<node_nums*2+2;i++)
		cmd = (char*)malloc(sizeof(char)*node_nums);
	scanf(" %s",cmd);
	printf("you have been inputed :%s\r\n",cmd);
	PreOrder_Create_Tree(&mytree);
	//PreOrder_Vist_Tree(mytree);
	
	printf("please input tree2 node nums!\r\n");
	scanf("%d",&node_nums);
	printf("please input node data of %d!\r\n",node_nums);
	for(int i=0;i<node_nums*2+2;i++)
		cmd = (char*)malloc(sizeof(char)*node_nums);
	scanf(" %s",cmd);
	printf("you have been inputed :%s\r\n",cmd);
	PreOrder_Create_Tree(&mytree_cmp);
	//PreOrder_Vist_Tree(mytree_cmp);
	
	printf("%s",(similar_rcgn(mytree,mytree_cmp))?("t1 is unsimilar to t2\r\n"):("t1 is similar to t2\r\n"));
}