#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "fcntl.h"
#include "sys/types.h"
#include "string.h"
#include <procession.h>
//1.获取数组长度
int Get_Len(Element_Type *array)
{
    int ct = 0;

    switch(sizeof(Element_Type))
    {
        case 1:return (int)(strlen((char*)array));break;
        default:while(*array != 65536){
            array++;
            ct++;
        };return (ct);break;
    }
}
//2.显示数组
void ARRAY_SHOW(Element_Type *array)
{
    for(int i=0;i<Get_Len(array);i++)
    {
        switch(sizeof(Element_Type))
        {
            case 1:printf("%4c",array[i]);break;
            default:printf("%4d",array[i]);break;
        }
    }
    printf("\r\n");
}
//3.冒泡排序
void Maopao_Process(Element_Type *array)
{
    for(int i=0;i<Get_Len(array);i++)
    {
        for(int j=0;j<Get_Len(array)-i-1;j++)
        if(array[j] > array[j+1])
        {
            Element_Type ts;
            ts = array[j+1];
            array[j+1] = array[j];
            array[j]   = ts;
        }
        ARRAY_SHOW(array);
    }
}
//4.插入排序
void Insert_Process(Element_Type *array)
{
    int i,j;
    Element_Type order_array[100] = {0};
    order_array[0] = array[0];//先摸一张牌
    
    for(i=1;i<Get_Len(array);i++)//牌堆剩余的牌
    {
        for(j=0;j<i;)//和手牌比较
        {
            if( order_array[j] > array[i] )//手牌大于摸到的牌
            {
                //从这张牌开始往后顺移
                for(int k=i;k>j;k--)
                {
                    order_array[k] = order_array[k-1];
                }
                //插入摸到的手牌
                order_array[j] = array[i];
                break;//找到位置插入手牌即可
            }  
            j++;
        }
        if(i == j)
        {
            order_array[j] = array[i];
        }
    }
    order_array[Get_Len(array)] = Int_End;
    for(i=0;i<Get_Len(array);i++)
        array[i] = order_array[i];

    ARRAY_SHOW(array);
}   
//5.希尔排序
void Swap(Element_Type *x1,Element_Type *x2)
{
    Element_Type ts;
    ts = *x2;
    *x2 = *x1;
    *x1 = ts;
}
void Shell_Sort(Element_Type *array)
{
    int len;
    int gap;
    int flag = 1+2;//gap归零后还要做两遍
    len = Get_Len(array);
    gap = len/2;
    while(gap && flag)
    {
        for(int i=0;i<(len-gap);i++)
        {
            if(array[i] > array[i+gap])
            {
                Swap(&array[i],&array[i+gap]);
            }
        }
        if(gap == 1)
        {
            flag--;
        }
        else
        {
            gap /= 2;
        }
    }
}
//6.快速排序
int Quick_Sort_step(Element_Type *array,int low,int high)
{
    //int low = 0;
    //int high = Get_Len(array)-1;
    int tmp;
    int dir = 1;
    //1.获取基准值
    tmp = array[low];

   while(high != low)
   {
        //2.先从后往前扫描，比较
        if(dir)
        {
            if(array[high] <= tmp)
            {
                array[low] = array[high];
                dir = !dir;
            }
            else
                high--;
        }
        //3.有换位后改变扫描方向
        else
        {
            if(array[low] > tmp)
            {
                array[high] = array[low];
                dir = !dir;
            }
            else
                low++;
        }
    }
    //4.把tmp里的值给array[low/high]
    array[high] = tmp;
    return high;
}
void Quick_Sort(Element_Type *array,int low ,int high)
{
    int index;
    index = Quick_Sort_step(array,low,high);
    //printf("low:%d->high:%d\tindex:%d\r\n",low,high,index);
    if( (index > low) && (index-1 != low) )
        Quick_Sort(array,0,index-1);
    if( (index < high) && (index+1 != high) )
        Quick_Sort(array,index+1,high);
}
//7.简单选择排序
struct Max{
    Element_Type val;
    unsigned     index;
};
struct Max Max_Emt={
    .val = 0,
    .index = 0,
};
void Sample_Sort(Element_Type *array)
{
    int len = Get_Len(array);
    Element_Type ts;

    for(int i=0;i<len;i++)
    {
        //1.找无序序列里的最大值/最小值
        Max_Emt.val = array[0];
        Max_Emt.index = 0;
        for(int j=0;j<len-i;j++)
        {
            if(Max_Emt.val < array[j])
            {
                Max_Emt.index = j;
                Max_Emt.val   = array[j];
            }
        }
        //2.把最大值/最小值放到序列最后，下次查找忽略最后一位
        ts = array[len - i -1];
        array[len - i -1] = Max_Emt.val;
        array[Max_Emt.index] = ts; 
        //ARRAY_SHOW(array);
    }
}
//8.堆排序
//9.归并排序





