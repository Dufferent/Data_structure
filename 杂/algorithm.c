#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/types.h"
#include "fcntl.h"
#include "string.h"

typedef int elemtype;

typedef struct list{
    struct list *next;
    elemtype date;
}*Link,LNode;

typedef struct tree{
    struct tree *lchild;
    struct tree *rchild;
    elemtype date;
}*BTree,BNode;

typedef struct{
    elemtype *q;
    int size;
    int rear;
    int front;
}Queue;

typedef struct{
    elemtype *data;
    int size;
    int top;
}Stack;

typedef struct{
    elemtype *d;
    int maxsize;
}heap;


#define NHead
//[list reverse]
Link Reverse(Link *obj)
{
    Link op = (*obj);
    Link pre,cur,next;
#ifdef NHead
    pre = NULL;
    cur = op;
    next = cur->next;
#else
    pre = op;
    cur = pre->next;
    next = cur->next;
    pre->next=NULL;
#endif
    while(next)
    {
        cur->next=pre;
        pre=cur;
        cur=next;
        next=cur->next;
        if(!next)
            cur->next=pre;
    }
    return cur;
}

int List_Init(Link *obj,int len)
{
#ifdef NHead
    (*obj) = (Link)malloc(sizeof(LNode));
    Link op = (*obj);
    printf("please input the first val\r\n");
    scanf("%d",&op->date);
    for(int i=0;i<len;i++)
    {
        Link nNodw = (Link)malloc(sizeof(LNode));
        printf("please input the %d val\r\n",i+1);
        scanf("%d",&nNodw->date);
        nNodw->next = NULL;
        op->next = nNodw;
        op=op->next;
    }
#else

#endif   
    return 0;
}

void Vist(Link obj)
{
    printf("[list:]");
    for(Link vs=obj;vs;vs=vs->next)
    {
        printf("%2d",vs->date);
    }
    printf("\r\n");
}

int S_Init(Stack *s,int size)
{
    s->data = (elemtype*)malloc(sizeof(elemtype)*size);
    s->size = size;
    s->top = 0;
}

int Push(Stack *s,elemtype dat)
{
    if(s->top != s->size)
    {
        s->data[s->top] = dat;
        s->top++;
        return 0;
    }
    else
    {
        printf("Stack is full!\r\n");
        return -1;
    }
}

elemtype Pop(Stack *s)
{
    if(s->top != 0)
    {
        s->top--;
        return s->data[s->top];
    }
    else
    {
        printf("Stack is empty!\r\n");
        return -1;
    }
}

int Q_Init(Queue *line,int size)
{
    line->q = (elemtype*)malloc(sizeof(elemtype)*size);
    line->size = size;
    line->rear = 0;
    line->front = 0;
    return 0;
}

int InQueue(Queue *line,elemtype dat)
{
    if(line->rear != line->size)
    {
        line->q[line->rear] = dat;
        line->rear++;
        return 0;
    }
    else
    {
        printf("Queue is full!\r\n");
        return -1;
    }
}

elemtype OutQueue(Queue *line)
{
    elemtype ret;
    if(line->front != line->rear)
    {
        ret =  line->q[line->front];
        line->q[line->front] = 0;
        line->front++;
        return ret;
    }
    else
    {
        printf("Queue is empty!\r\n");
        return -1;
    }    
}

int fun(Stack *A,Queue *B,int n)
{
    int ret = Pop(A);
    if(ret != -1 )
    {
        InQueue(B,ret);
        for(int i=0;i<n-1;i++)
            InQueue(B,OutQueue(B));
        fun(A,B,n+1);
    }
    return 0;
}

int maxheap(heap *h,int index)
{
    int max;
    int cur = index;
    if(cur > ((h->maxsize)/2))
        return -1;//overflow
    maxheap(h,index+1);
    int lchild = cur*2;
    int rchild = cur*2+1;
    // printf("ld-%d rd-%d\r\n",lchild,rchild);
    if( ((h->d[lchild] > h->d[rchild]) && (lchild <= h->maxsize)) || ((lchild <= h->maxsize) && (rchild > h->maxsize)) )
    {
        max = h->d[lchild];
        if(h->d[cur] < max)
        {
            h->d[lchild] = h->d[cur];
            h->d[cur] = max;
            maxheap(h,lchild);
        }
    }
    else if( rchild <= h->maxsize )
    {
        max = h->d[rchild];
        if(h->d[cur] < max)
        {
            h->d[rchild] = h->d[cur];
            h->d[cur] = max;
            maxheap(h,rchild);
        }
    }
    return 0;
}

int heap_store(heap *h)
{
    while(h->maxsize){
        h->d[0] = h->d[1];
        h->d[1] = h->d[h->maxsize];
        h->d[h->maxsize] = h->d[0];
        h->maxsize--;
        maxheap(h,1);
        for(int i=1;i<11;i++)
            printf("heap:%-3d",h->d[i]);
        printf("maxsize%-2d\r\n",h->maxsize);
    }
    return 0;
}

int data[]={0,1,2,3,5,7,4,8,15,6,11};

int main(int argc,char** argv)
{
    // Link ml;
    // List_Init(&ml,5);
    // Vist(ml);
    // Vist(Reverse(&ml));
    // Stack ms;
    // S_Init(&ms,atoi(argv[1]));
    // for(int i=0;i<atoi(argv[1]);i++)
    //     Push(&ms,1);
    // for(int i=0;i<5;i++)
    //     printf("Pop:%2d\r\n",Pop(&ms));    
    // Queue mq;
    // Q_Init(&mq,atoi(argv[1])*10);
    // for(int i=0;i<atoi(argv[1]);i++)
    //     InQueue(&mq,2);
    // for(int i=0;i<5;i++)
    //     printf("out:%2d\r\n",OutQueue(&mq));      
    // fun(&ms,&mq,atoi(argv[1]));

    // for(int i=0;i<mq.size;i++)
    //     printf("out:%2d\r\n",mq.q[i]);     
    heap mh;
    //mh.d = (elemtype*)malloc(sizeof(elemtype)*5);
    mh.d = data;
    mh.maxsize = 10;

    maxheap(&mh,1);
    // for(int i=1;i<11;i++)
    //     printf("heap:%2d\r\n",mh.d[i]);
    heap_store(&mh);
    for(int i=1;i<11;i++)
        printf("heap:%2d\r\n",mh.d[i]);
    return 0;
}