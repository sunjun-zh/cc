#include <stdio.h>
#define MaxSize 50

typedef int ElemType;

typedef struct
{
    /* data */
    ElemType data[MaxSize]; //存放队列元素
    int front, rear;        //队头指针和队尾指针
} SqQueue;

//1.在循环队列的类型结构中，增设一个tag的整型变量，进队时置tag为1,出队时为0
/*
    只有入队操作可能导致队满，出队操作可能导致队空
    队空条件: Q.front==Q.rear 且 Q.tag==0
    队满条件: Q.front==Q.rear 且 Q.tag==1
    进队操作: Q.data[Q.rear]=x; Q.rear=(Q.rear=Q.rear+1)%MaxSize; Q.tag=1
    出队操作: x=Q.data[Q.front]; Q.front=(Q.front+1)%MaxSize; Q.tag=0
*/

//2.Q是一个队列，S是一个空栈，实现将队列中的元素逆置的算法
void Inverser(Stack S, Queue Q)
{
    while (!QeueuEmpty(Q))
    {
        x = DeQueue(Q); //队列中的全部元素依次出队
        Push(S, x);     //元素依次入栈
    }

    while (!StackEmpty(S))
    {
        Pop(S, x);     //栈中全部元素依次出栈
        EnQueue(Q, x); //入队
    }
}

//3.使用两个栈S1 S2来模拟一个队列
//3-1入队算法
int EnQueue(Stack &S1, Stack &S2, ElemType e)
{
    if (!StackOverflow(S1))
    {
        Push(S1, e);
        return 1;
    }
    if (StackOverflow(S1) && !StackEmpty(S2))
    {
        printf("队列满");
        return 0;
    }
    if (StackOverflow(S1) && StackEmpty(S2))
    {
        while (!StackEmpty(S1))
        {
            Pop(S1, x);
            Push(S2, x);
        }
    }
    Push(S1, e);
    return 1;
}

//3-2 出队算法
void DeQueue(Stack &S1, Stack &S2, ElemType &x)
{
    if (!StackEmpty(S2))
    {
        Pop(S2, x);
    }
    else if (StackEmpty(S1))
    {
        printf("队列为空");
    }
    else
    {
        while (!StackEmpty(S1))
        {
            Pop(S1, x);
            Push(S2, x);
        }
    }
    Pop(S2, x);
}

// 3-3判断队列为空
int QueueEmpty(Stack S1, Stack S2)
{
    if (StackEmpty(S1) && StackEmpty(S2))
        return 1;
    else:
        return 0;
}