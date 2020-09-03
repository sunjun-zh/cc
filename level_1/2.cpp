//单链表
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

// 声明结点的类型和指向结点的指针类型
/*
    定义链表L LinkList L; （头指针）
    定义结点指针 Lnode * p; <===> LinkList p;
*/
typedef struct LNode
{
    ElemType data;      //结点的数据域
    struct LNode *next; //结点的指针域

} LNode, *LinkList; //LinkList 为指向结构体Lnode的指针类型

// 初始化
Status InitList(LinkList &L)
{
    // 生产新结点作为结点头， 用头指针L指向头结点
    L = new LNode; // L = (LinkList)malloc(sizeof(LNode))
    L->next = NULL;
    return OK;
}

// 判断是否为空 链表中无元素，成为空链表(头指针和头结点仍然存在)
int ListEmpty(LinkList L)
{
    if (L->next)
        return 0;
    else
        return 1;
}

// 销毁单链表L
/*
    L==NULL <==> L
    L 为头指针  L = 头结点的地址;
    p = L; p指向头结点
    p = L->next; p指向首元结点
*/
Status DestroyList_L(LinkList &L)
{
    LNode *p; // 或LinkList p;
    while (L) // while(L!=NULL)
    {
        p = L;
        L = L->next;
        delete p; // free(p)
    }
    return OK;
}

// 清空单链表
Status ClearList_L(LinkList &L)
{
    LNode *p, *q; // 或LinkList p;
    p = L->next;  //首元结点
    while (p)
    {
        q = p->next;
        delete p;
        p = q;
    }
    L->next = NULL;
    return OK;
}

// 链表的长度
int ListLength_L(LinkList L)
{
    LNode *p;    // LinkList=p
    p = L->next; // 从首元结点开始
    int length = 0;
    while (p)
    {
        length++;
        p = p->next;
    }
    return length;
}

// 取值 -- 取第i个元素
Status GetElem_L(LinkList L, int i, ElemType &e)
{
    LNode *p = L->next; //
    int j = i;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return ERROR;
    e = p->data;
    return OK;
}

// 查找 -- 按值返回结点
LNode *LocateElem_L(LinkList L, ElemType e)
{
    LNode *p = L->next;
    while (p && p->data != e)
    {
        p = p->next;
    }
    return p;
}
// 查找 -- 按值返回位置序号
int LocateElem_L_2(LinkList L, ElemType e)
{
    LNode *p = L->next;
    int j = 1;
    while (p && p->data != e)
    {
        p = p->next;
        j++;
    }
    if (p)
        return j;
    else
        return 0;
}

// 插入 在第i个结点前插入值为e的新结点
Status ListInsert_L(LinkList &L, int i, ElemType e)
{
    LNode *p = L;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > j - 1)
        return ERROR;
    LNode *s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

// 删除--第i个结点
Status ListDelete_L(LinkList &L, int i, ElemType &e)
{
    LNode *p;
    LNode *q;
    p = L; // 头结点
    int j = 0;
    //寻找第i个结点的前驱结点
    while (p->next && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    // 位置是否合法
    if (!(p->next) || j > i - 1)
        return ERROR;
    q = p->next;
    p->next = q->next;
    e = q->data;
    delete q;
    return OK;
}

// 建立单链表 -- 头插法  (插入n个元素)
void CreateList_H(LinkList &L, int n)
{

    L = new LNode;
    //先建立一个带头结点的单链表
    L->next = NULL;
    int i;
    for (i = n; i > 0; --i)
    {
        // 生产一个新的结点
        LNode *p = new LNode; // p = (LinkList)malloc(sizeof(LNode))
        int temp;
        scanf("%d", &temp);
        p->data = temp;

        p->next = L->next; // 插入到表头
        L->next = p;
    }
}
// 建立单链表 -- 尾插法
void CreateList_T(LinkList &L, int n)
{

    L = new LNode;
    //先建立一个带头结点的单链表
    L->next = NULL;
    LNode *r = L; //建立一个尾结点,并指向头结点

    int i;
    for (i = 0; i < n; ++i)
    {
        // 生产一个新的结点
        LNode *p = new LNode; // p = (LinkList)malloc(sizeof(LNode))
        int temp;
        scanf("%d", &temp);
        p->data = temp;
        p->next = NULL;
        r->next = p; //插入到表尾
        r = p;       // r指向新的尾结点
    }
}

int main()
{
    /*
        重要操作：
            p = L; //p指向头结点
            s=L->next; //s指向首元即结点
            p = p->next;//p指向下一个结点
    */

    return 0;
}