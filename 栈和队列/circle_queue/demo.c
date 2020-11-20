#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "sys/types.h"
#include "fcntl.h"

#include "./circle_queue.h"

int main(int argc,char** argv)
{
    CirQueue MyCQ;
    CQ_Init(&MyCQ,6);
    for(int i=0;i<4;i++)
        CQ_In(&MyCQ,i);

    for(int i=0;i<5;i++)
        printf("%d out!\r\n",CQ_Out(&MyCQ));

    for(int i=0;i<4;i++)
        CQ_In(&MyCQ,i);
    
    for(int i=0;i<3;i++)
        printf("%d out!\r\n",CQ_Out(&MyCQ));

    for(int i=0;i<3;i++)
        CQ_In(&MyCQ,i);

    for(int i=0;i<4;i++)
        printf("%d out!\r\n",CQ_Out(&MyCQ));


    return 0;
}