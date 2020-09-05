// 队列 -- 顺序队列(循环队列)
#include <stdio.h>
#include <stdlib.h>

#define MAXQSIZE 100
// 函数结果状态码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

// Status 是函数的类型，其值是函数结果的状态码
typedef int Status;
typedef int QElemType;

//定义队列
typedef struct 
{
    QElemType *base; // 初始化的动态分配存储空间
    int front;       //头指针 -- 队头元素的下标
    int rear;        //尾指针 -- 队尾元素的下标
} SqQueue;

// 初始化 (分配内存空间)
Status InitQueue(SqQueue &Q)
{
    //分配数组空间
    Q.base = new QElemType[MAXQSIZE]; // Q.base = (QElemType*）malloc(MAXQSIZE*sizeof(QElemType))
    // 存储分配失败
    if (!Q.base)
        exit(OVERFLOW);
    //头指针尾指针置为0，队列为空
    Q.front = Q.rear = 0;
    return OK;
}

//循环队列长度
int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

//入队 -- 解决假上溢的方法:循环队列
Status EnQueue(SqQueue &Q, QElemType e)
{
    //判断是否队满
    if ((Q.rear + 1) % MAXQSIZE == Q.front)
        return ERROR;
    //新元素加入队尾
    Q.base[Q.rear] = e;
    //队尾指针加1
    Q.rear = (Q.rear + 1) % MAXQSIZE;
    return OK;
}

//出队 -- 循环队列(总是保持一个元素为空)
Status DeQueue(SqQueue &Q, QElemType &e)
{
    //判断是否队空
    if (Q.front == Q.rear)
        return ERROR;
    //保存队头元素
    e = Q.base[Q.front];
    //队头指针加1
    Q.front = (Q.front + 1) % MAXQSIZE;
    return OK;
}

//取队头元素
QElemType GetHead(SqQueue Q)
{
    if (Q.front != Q.rear)
        return Q.base[Q.front];
}

int main()
{

    return 0;
}