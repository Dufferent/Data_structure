#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "unistd.h"
#include <stack.h>

#define STACK_SIZE 16


const ELEMENT_TYPE Stack_data[STACK_SIZE] = {'a','b','c','d','e','f','g','h','i','j'};
//进制转换
Status Dec_to_Bin(unsigned int num)
{
    int ct = 0;
    STACK my_stack;
    Stack_Init(&my_stack,STACK_SIZE);
    while(num)
    {
        Stack_Push(&my_stack,num%2);
        num /= 2;
        ct++; 
    }

    //show
    printf("%s","0x");
    for(int i=0;i<ct;i++)
    {
        printf("%d",Stack_Pop(&my_stack));
    }
    printf("\r\n");
    return OKAY;
}
//括号匹配
Status Match_Ts(void)
{
    char ptr[20] = {0};
    char ret;
    char* p = ptr;
    STACK my_stack;
    Stack_Init(&my_stack,STACK_SIZE);

    printf("please input str!\r\n");
    scanf("%s",ptr);
    while(*p != '\0')
    {
        if( (*p == '[') || (*p == '(' ) || (*p == '{') )
            Stack_Push(&my_stack,*p);
        else
        {
            ret = Stack_Pop(&my_stack);
            if( ret < 0 )
                {printf("Match failed!\r\n");return FALSE;}
            else
            {
                switch(*p)
                {
                    case ']':if(ret == '[');else {printf("Match failed!\r\n");return FALSE;}break;
                    case ')':if(ret == '(');else {printf("Match failed!\r\n");return FALSE;}break;
                    case '}':if(ret == '{');else {printf("Match failed!\r\n");return FALSE;}break;
                    default:break;
                }
            }
        }
        p++;
    }
    printf("Match successful!\r\n");
    return OKAY;
}
//终端输入
Status Terminal_Input(void)
{
    char ptr[20] = {0};
    char terminal[20] = {0};
    char ret;
    char* p = ptr;
    STACK my_stack;
    Stack_Init(&my_stack,STACK_SIZE);

    printf("please input str!\r\n");
    scanf("%s",ptr);getchar();

    while(*p != '\0')
    {
        if( *p == '#' )
        {
            Stack_Pop(&my_stack);
        }
        else if( *p == '@' )
        {
            while(ret != INCREABLE)
                ret = Stack_Pop(&my_stack);
        }
        else
        {
            Stack_Push(&my_stack,*p);
        }
        p++;
    }
    for(int i=strlen(ptr);i>0;i--)
    {
        terminal[i-1] = Stack_Pop(&my_stack);
    }
    printf("%s\r\n",terminal);
    return OKAY;
}
//表达式求值***
#define In(x) (c>=48) && (c<=57) ? 1:0
ELEMENT_TYPE Compare(char d1,char d2)//d1为前一个操作符，d2为现在处理的操作符
{
    if(d2 == '+')
    {
        switch(d1)
        {
            case '+':return '>';break;
            case '-':return '>';break;
            case '*':return '>';break;
            case '/':return '>';break;
            case '(':return '<';break;
            case ')':return '>';break;
            case '#':return '<';break;
        }
    }
    if(d2 == '-')
    {
        switch(d1)
        {
            case '+':return '>';break;
            case '-':return '>';break;
            case '*':return '>';break;
            case '/':return '>';break;
            case '(':return '<';break;
            case ')':return '>';break;
            case '#':return '<';break;
        }
    }
    if(d2 == '*')
    {
        switch(d1)
        {
            case '+':return '<';break;
            case '-':return '<';break;
            case '*':return '>';break;
            case '/':return '>';break;
            case '(':return '<';break;
            case ')':return '>';break;
            case '#':return '<';break;
        }
    }
    if(d2 == '/')
    {
        switch(d1)
        {
            case '+':return '<';break;
            case '-':return '<';break;
            case '*':return '>';break;
            case '/':return '>';break;
            case '(':return '<';break;
            case ')':return '>';break;
            case '#':return '<';break;
        }
    }
    if(d2 == '(')
    {
        switch(d1)
        {
            case '+':return '<';break;
            case '-':return '<';break;
            case '*':return '<';break;
            case '/':return '<';break;
            case '(':return '<';break;
            case '#':return '<';break;
            //case ')':return '>';break;
            //')'已经去掉了，或者出错了
        }
    }
    if(d2 == ')')
    {
        switch(d1)
        {
            case '+':return '>';break;
            case '-':return '>';break;
            case '*':return '>';break;
            case '/':return '>';break;
            case '(':return '=';break;
            case ')':return '>';break;
            //case '#':return '<';break;
        }
    }
    if(d2 == '#')
    {
        switch(d1)
        {
            case '+':return '>';break;
            case '-':return '>';break;
            case '*':return '>';break;
            case '/':return '>';break;
            //case '(':return '=';break;
            case ')':return '>';break;
            case '#':return '=';break;
        }
    }
}
ELEMENT_TYPE Process(int num1,char symbol,int num2)
{
    switch(symbol)
    {
        case '+':return ((num1+num2)+48);break;
        case '-':return ((num1-num2)+48);break;
        case '*':return ((num1*num2)+48);break;
        case '/':return ((num1/num2)+48);break;
    }
}


Status Formula_Culcu()
{
    STACK num;
    STACK op;
    char c;
    Stack_Init(&num,STACK_SIZE);
    Stack_Init(&op,STACK_SIZE);

    //前期准备
    Stack_Push(&op,'#');

    printf("please input c!\r\n");
    scanf("%c",&c);
    getchar();
    while(c != '#' || Get_Top(op) != '#')
    {
        if( (c>=48) && (c<=57) )//操作数进栈
        {
            Stack_Push(&num,c);
            scanf("%c",&c);
            getchar();
            printf("Compare consequence:%c\r\n",Compare(Get_Top(op),c));
        }
        else
        {   //判断操作符优先级
            switch( Compare(Get_Top(op),c) )
            {
                case '<':Stack_Push(&op,c);scanf("%c",&c);getchar();break;
                case '=':Stack_Pop(&op);scanf("%c",&c);getchar();break;
                case '>':
                {
                    int num1,num2;
                    char symbol;
                    symbol = Stack_Pop(&op);
                    num1   = (Stack_Pop(&num)-48);
                    num2   = (Stack_Pop(&num)-48);
                    Stack_Push(&num,Process(num1,symbol,num2));
                }
                break;
            }
        }
    }
    printf("consequent is:%d\r\n",(int)Get_Top(num)-48);
}

int main(void)
{
    STACK my_stack;

    Stack_Init(&my_stack,STACK_SIZE);
    for(int i=0;i<STACK_SIZE;i++)
        Stack_Push(&my_stack,Stack_data[i]);

    for(int i=0;i<STACK_SIZE;i++)
        printf("%c",Stack_data[i]);
    printf("\n");

    for(int i=0;i<STACK_SIZE;i++)
        printf("%c",Stack_Pop(&my_stack));
    printf("\n");

    Dec_to_Bin(33);
    //Match_Ts();
    //Terminal_Input();
    Formula_Culcu();
    return 0;
}