#include "stdio.h"
#include <chains_list.h>

int main(void)
{
    LNode my_list;

    Chains_List_Init(&my_list,10);
    View_List(my_list);

    Insert_Chains_List(&my_list,12,'a');
    Insert_Chains_List(&my_list,10,'b');
    Insert_Chains_List(&my_list, 5,'c');
    View_List(my_list);

    Delete_Index(&my_list,5);
    Delete_Val(&my_list,'b');
    View_List(my_list);

    Delete_Node(&my_list,5);
    Delete_Node_V(&my_list,'a');
    View_List(my_list);
    
    Insert_Chains_List(&my_list,1,'s');
    View_List(my_list);
    Delete_Node(&my_list,1);
    View_List(my_list);
    
    return 0;
}