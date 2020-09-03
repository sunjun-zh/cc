//循环链表
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
typedef int ElemType;

typedef struct LNode
{
    ElemType data;      //结点的数据域
    struct LNode *next; //结点的指针域

} LNode, *LinkList; //LinkList 为指向结构体Lnode的指针类型

// 带尾指针单循环链表合并 Ta Tb链表的尾指针（an的存储位置）
LinkList Connect(LinkList Ta, LinkList Tb)
{
    LNode *p = Ta->next;       //p为表头结点
    Ta->next = Tb->next->next; // tb表头链接ta表尾
    delete Tb->next;
    Tb->next = p;
    return Tb;
}


int main(){

    return 0;
}
