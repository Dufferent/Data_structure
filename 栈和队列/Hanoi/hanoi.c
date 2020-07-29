#include "stdio.h"
#include "stdlib.h"
#include "fcntl.h"
#include "unistd.h"
#include "sys/types.h"
#include "string.h"

void hanoi(int n,char x,char y,char z)
{
    if(n == 1)
    {
        printf("%c->%c\r\n",x,z);//只有一个圆盘需要移动
    }
    else
    {
        hanoi(n-1,x,z,y);//先将x压在最后一块圆盘上的n-1快圆盘移动到y上
        printf("%c->%c\r\n",x,z);//将x底部的圆盘移动到z上
        hanoi(n-1,y,x,z);//将y上的n-1块圆盘移动到z上
    }
}



int main(void)
{
    hanoi(3,'a','b','c');
    return 0;
}