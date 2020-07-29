#include "stdio.h"
#include "stdlib.h"
#include "fcntl.h"
#include "unistd.h"
#include "sys/types.h"
#include "string.h"

#define x  3
#define y  3
#define Rect_Type int
//1.矩阵转置
int T_Rect(Rect_Type **obj)
{
    for(int i=0;i<y;i++)
    for(int j=0;j<i;j++)
    {
        int ts;
        ts = obj[i][j];
        obj[i][j] = obj[j][i];
        obj[j][i] = ts;
    }
    return 0;
}
//2.压缩
Rect_Type *Rect_Press(Rect_Type **obj)
{
    Rect_Type pre_rect[x*y] = {0};
    Rect_Type *p;
    for(int i=0;i<y;i++)
    for(int j=0;j<=i;j++)
    {
        pre_rect[i*y+j] = obj[i][j];
    }    
    p = pre_rect;
    return p;
}
//3.解压



void Rect_Show(Rect_Type **obj)
{
    for(int i=0;i<y;i++)
    {
        for(int j=0;j<x;j++)
        {
            printf("%2d",obj[i][j]);
        }
        printf("\r\n");
    }
}

int main(void)
{
    Rect_Type rect[y][x] = {
        {1,2,3},
        {2,2,4},
        {3,4,3},
    };
    Rect_Type *get_press;
    //解压
    Rect_Type *(ret[x]);
    Rect_Type extract[y][x] = {0};
    //解压
    Rect_Type *(rect_pt[x]);
    for(int i=0;i<y;i++)
        rect_pt[i] = rect[i];


    Rect_Show(rect_pt);
    T_Rect(rect_pt);
    printf("\r\n");
    printf("\r\n");
    Rect_Show(rect_pt);
    get_press = Rect_Press(rect_pt);
    for(int i=0;i<x*y;i++)
        printf("%2d",get_press[i]);

    //printf("\r\n");
    //printf("\r\n");

    //解压
    for(int i=0;i<x*y;i++)
    {
        extract[i/3][i%3] = get_press[i];
        printf("%2d",get_press[i]);
    }
       
    for(int i=0;i<y;i++)
    for(int j=x-1;j>i;j--)
    {
        extract[i][j] = extract[j][i];
    }
    printf("\n");
    for(int i=0;i<y;i++)
        ret[i] = extract[i];

    printf("\n");
    Rect_Show(ret);

    return 0;
}