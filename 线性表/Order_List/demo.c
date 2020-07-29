#include "stdio.h"
#include <order_list.h>

int main(void)
{
    Order_List my_list;

    Order_List_Init(&my_list,32);
    Insert_Element(&my_list,16,'a');
    Look_Element(&my_list,16);
    Delete_Element(&my_list,16);
    Look_Element(&my_list,16);

    return 0;
}