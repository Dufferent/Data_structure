#include "stdio.h"
#include "stdlib.h"

void main(void)
{
	int alive;	// [alive people nums]
	int all;	// [nums of all people]
	int J;		// circle num(s)
	
	int *man;	// [participated mans]
#define D 0	// ---- [died]
#define L 1	// ---- [live]
	
	printf("please input num of all!\r\n");
	scanf("%d",&all);
	printf("please input num of alive!\r\n");
	scanf("%d",&alive);
	printf("please input num of J!\r\n");
	scanf("%d",&J);
	
	printf("play mans: [%d]\r\n\
needalive: [%d]\r\n\
circlenum: [%d]\r\n",all,alive,J);
	
	// [init mans]
	man = (int *)malloc(sizeof(int)*all);
	for(int i=0;i<all;i++)
		man[i] = L;	// people all live
	
	// [game start]
	int pos = 0;		// [position]
	int nums = 0;
	int outnums = 0;
	while(outnums < all)
	{
		nums++;	// man[0] -> 1 ...
		if(nums==3)
		{
			nums=1;	//重新报数
			if(man[pos] == L)
			{
				man[pos] = D;	
				printf("%d->",pos+1);
				pos = (pos+1)%all;
				while(man[pos]==D && outnums < (all-1))pos = (pos+1)%all;
			}
			outnums++;			
		}
		pos = (pos+1)%all;
		while(man[pos]==D && outnums < all)pos = (pos+1)%all;
	}
}