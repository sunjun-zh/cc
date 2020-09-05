// 链队 -- (若用户无法估计所用队列的长度，则适宜采用链队列)
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

//链式队列类型的定义
typedef struct Qnode
{
    QElemType data;
    struct Qnode *next;
} QNode, *QueuePtr;

typedef struct
{
    QueuePtr front; //队头指针
    QueuePtr rear;  //队尾指针
} LinkQueue;

// 初始化 (分配内存空间)
Status InitQueue(LinkQueue &Q)
{
    //分配数组空间,都指向头结点
    Q.front = Q.rear = (QueuePtr)malloc(MAXQSIZE * sizeof(QNode));
    Q.front->next = NULL;
    return OK;
}

//销毁链队列--从队头结点开始，依次释放所有结点
Status DestroyQueue(LinkQueue &Q)
{
    while (Q.front)
    {
        QNode *p = Q.front->next; //p指向头指针 //Q.rear=Q.front->next;free(Q.front);Q.front=Q.rear;
        free(Q.front);
        Q.front = p;
    }
    return OK;
}

//入队
Status EnQueue(LinkQueue &Q, QElemType e)
{
    QNode *p = (QueuePtr)malloc(sizeof(QNode));
    if (!p)
        exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

//出队
Status DeQueue(LinkQueue &Q, QElemType &e)
{
    //判断是否队空
    if (Q.front == Q.rear)
        return ERROR;

    QNode *p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    //若要删除尾结点，则需要将尾结点也指向头结点 
    if (Q.rear == p)
        Q.rear = Q.front;
    delete p;
    return OK;
}

//取队头元素
Status GetHead(LinkQueue Q, QElemType &e)
{
    //判断是否队空
    if (Q.front == Q.rear)
        return ERROR;
    e = Q.front->next->data;
}

int main()
{

    return 0;
}