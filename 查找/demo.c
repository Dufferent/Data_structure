#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "inspect.h"
Tree_Data_Type *str;
int main(void)
{
    Element_Type array[] = {'c','d','a','f','b','e','g','k'};
    Element_Type sort_array[] = {'a','b','c','d','e','f','g','h'};
    Tree_Data_Type *op = str;
    BNode my_tree;
    BNode find;
    str = (Tree_Data_Type*)malloc(sizeof(Tree_Data_Type)*32);


    //int ret = Inspect_Directly(array,'f');
    //int ret = Sort_Inspect(sort_array,'g',SMALL_TO_BIG);
    //int ret = Half_Inspect(sort_array,0,Get_Len(array)-1,'c',SMALL_TO_BIG);

    printf("please scanf Inspect tree by order!\nsuch as \' data+回车 \'\r\n");
    Input_buf(str);
    Show_buf(str);

    my_tree = Creat_Inspect_Tree(&my_tree);
    Vist_Inspect_Tree(my_tree);
    printf("\r\n");
    find = Inspect_The_Tree(my_tree,4);

    if(find != NULL)
        printf("find it:%d\r\n",find->data);
    else
        printf("can't find\r\n");
    /*
    if(ret<0)
        printf("Inspect failed!\r\n");
    else
        printf("Index:%d!\r\n",ret);
    */

    return 0;
}