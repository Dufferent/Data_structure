#ifndef __INSPECT_H
#define __INSPECT_H

/* data type */
#define Element_Type char
#define SMALL_TO_BIG  1
#define BING_TO_SMALL 0

/* B-Tree */
#define Tree_Data_Type int
#define Tree_End       65536
#define _              -1
typedef struct bt{
    Tree_Data_Type data;
    struct bt *lchild;
    struct bt *rchild;
}Btree,*BNode;

extern Tree_Data_Type *str;
/* op */
BNode New_BNode(Tree_Data_Type data);
void Input_buf(Tree_Data_Type *p);
void Show_buf(Tree_Data_Type *p);
BNode Creat_Inspect_Tree(BNode *obj);//中序
void Vist_Inspect_Tree(BNode obj);//中序遍历
BNode Inspect_The_Tree(BNode obj,Tree_Data_Type val);

/* procession function */
int Get_Len(Element_Type *array);
void ARRAY_SHOW(Element_Type *array);
int Inspect_Directly(Element_Type *array,Element_Type val);
int Sort_Inspect(Element_Type *array,Element_Type val,unsigned int dir);
int Half_Inspect(Element_Type *array,unsigned int s,unsigned int e,Element_Type val,unsigned int dir);

#endif