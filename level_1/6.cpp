// 栈 -- 顺序存储结构--顺序栈
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
// 函数结果状态码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

// Status 是函数的类型，其值是函数结果的状态码
typedef int Status;
typedef int SElemType;

/*
   初始化 进栈 出栈 取栈顶元素 
   top base 也可用定义为int的顺序表的下表

   栈中元素个数=top-base; //两个指针相减->元素的个数
*/

//定义顺序栈
typedef struct
{
    SElemType *base; //栈底指针
    SElemType *top;  //栈顶指针
    int stacksize;   // 栈可用最大容量
} SqStack;

// 初始化 (分配内存空间)
Status InitStack(SqStack &S)
{
    // s.base = (SElemType *)malloc(sizeof(SElemType)*MAXSIZE)
    S.base = new SElemType[MAXSIZE];
    // 存储分配失败
    if (!S.base)
        exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}

// 判读是否为空 top==base
Status StackEmpty(SqStack S)
{
    if (S.base == S.top)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

// 顺序栈长度
int StackLength(SqStack S)
{
    return S.top - S.base;
}

// 清空顺序栈
Status ClearStack(SqStack S)
{
    if (S.base)
        S.top = S.base;
    return OK;
}

// 销毁顺序栈
Status DestoryStack(SqStack &S)
{
    if (S.base)
        delete S.base;
    S.stacksize = 0;
    S.base = S.top = NULL;

    return OK;
}

//顺序栈入栈
Status Push(SqStack &S, SElemType e)
{
    //栈满
    if (S.top - S.base == S.stacksize)
        return ERROR;
    //top指针先赋值，后上移
    // *S.top =e;
    // S.top++;
    *S.top++ = e;
    return OK;
}

//顺序栈出栈
Status Pop(SqStack &S, SElemType &e)
{
    // 是否为空
    if (S.top == S.base)
        return ERROR;
    //top指针先下移，后赋值
    // --S.top;
    // e = *S.top;
    e = *--S.top;
    return OK;
}

int main()
{

    return 0;
}