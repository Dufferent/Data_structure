#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "queue.h"
#include "unistd.h"

int main(void)
{
    Queue my_queue;
    ELEMENT_TYPE *address;

    Queue_Init(&my_queue,10);

    /*
    for(int i=97;i<103;i++)
        Insert_Queue(&my_queue,(char)i);

    for(int i=0;i<10;i++)
        printf("%2c",Out_Queue(&my_queue));

    printf("\r\n");

    for(int i=106;i>96;i--)
        Insert_Queue(&my_queue,(char)i);

    for(int i=0;i<10;i++)
        printf("%2c",Out_Queue(&my_queue));

    printf("\r\n");
    */
   while(1)
   {
       static int i=0;
       i = (i+1)%10+48;
       Insert_Queue(&my_queue,(char)i);
       printf("%c\r\n",Out_Queue(&my_queue));

       usleep(300*1000);
   }

    return 0;
}