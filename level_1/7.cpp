// 栈 -- 链式存储结构--链栈(是运算受限的单链表，只能在链头进行操作  )
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
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
} StackNode, *LinkStack;

// 初始化 (分配内存空间)
Status InitStack(LinkStack &S)
{
    // 构造一个空栈，栈顶指针置为空
    S = NULL;
    return OK;
}

// 判读是否为空
Status StackEmpty(LinkStack S)
{
    if (S == NULL)
        return TRUE;
    else
        return FALSE;
}

//入栈
Status Push(LinkStack &S, SElemType e)
{
    StackNode *p = new StackNode; //生成新结点p
    p->data = e;                  //将新结点数据域置为e
    p->next = S;                  //将新结点插入栈顶
    S = p;                        //修改栈顶指针
    return OK;
}

//出栈
Status Pop(LinkStack &S, SElemType &e)
{
    if (S == NULL)
        return ERROR;
    e = S->data;
    StackNode *p = S;
    S = S->next;
    delete p;
    return OK;
}

int main()
{

    return 0;
}