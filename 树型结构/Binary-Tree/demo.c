#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "btree.h"

#define CMD_LEN 32 
char* ccmd;

int main(void)
{
    BNode my_tree;
    ccmd = (char *)malloc(sizeof(char)*CMD_LEN);
    scanf("%s",ccmd);
    getchar();
    printf("creat cmd:%s\r\n",ccmd);

    //1.先序
    
    my_tree = BTree_Order_Init(&my_tree);
    BTree_Order_Vist(my_tree);
    printf("\r\n");
//    BTree_Index(&my_tree);
//    printf("\r\n");
    //2.中序
    /*
    my_tree = BTree_Mid_Init(&my_tree);
    BTree_Mid_Vist(my_tree);
    printf("\r\n");
    */
    //3.后序
    /*
    my_tree = BTree_Last_Init(&my_tree);
    BTree_Last_Vist(my_tree);
    printf("\r\n");
    */
    BTree_Change_RL(&my_tree);
    BTree_Order_Vist(my_tree);
    printf("\r\n");
    return 0;
}
