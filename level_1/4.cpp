//双向链表
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

typedef struct DuLNode
{
    ElemType data;                //结点的数据域
    struct DuLNode *prior, *next; //结点的指针域

} DuLNode, *DuLinkList;

// 同单链表相同
DuLNode *GetElemP_Dul(DuLinkList &L, int i)
{
    DuLNode *p = new DuLNode;
    return p;
}

// 插入--在第i个位置之前插入元素e
Status ListInsert_Dul(DuLinkList &L, int i, ElemType e)
{
    DuLNode *p = new DuLNode;
    DuLNode *s;
    if (!(p = GetElemP_Dul(L, i)))
        return ERROR;
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    return OK;
}

// 删除--在第i个位置元素
Status ListDelete_Dul(DuLinkList &L, int i, ElemType e)
{
    DuLNode *p = new DuLNode;
    DuLNode *s;
    if (!(p = GetElemP_Dul(L, i)))
        return ERROR;
    e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    return OK;
}

int main()
{

    return 0;
}
