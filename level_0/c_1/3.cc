// 单链表
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

// 定义结点类型
typedef struct Node
{
    /* data */
    ElemType data;     // 数据域
    struct Node *next; // 指针域
} Node, *LinkedList;

// 初始化
LinkedList LinkedListInit()
{
    Node *L;
    L = (Node *)malloc(sizeof(Node)); //申请结点的空间

    // 判断是否有足够内存空间
    if (L == NULL)
    {
        printf("申请内存空间失败\n");
    }
    L->next = NULL; // 将next设置为NULL，初始长度为0的单链表
    return L;
}

//单链表的建立 -- 头插
LinkedList LinkedListCreatH()
{
    Node *L;
    L = (Node *)malloc(sizeof(Node)); //申请头结点的空间
    L->next = NULL;                   // 初始化一个空链表

    ElemType x;
    while (scanf("%d", &x) != EOF)
    {
        Node *p;
        p = (Node *)malloc(sizeof(Node));
        p->data = x;
        p->next = L->next;
        L->next = p;
    }
    return L;
}

//单链表的建立--尾插
LinkedList LinkedListCreatT()
{
    Node *L;
    L = (Node *)malloc(sizeof(Node)); // 申请头结点空间
    L->next = NULL;                   //初始化一个空链表
    Node *r;
    r = L; //r始终指向终端结点，开始时指向头结点
    ElemType x;
    scanf("%d", &x);

    while (x != -1)
    {
        Node *p;
        p = (Node *)malloc(sizeof(Node)); //申请新的结点
        p->data = x;
        r->next = p;
        r = p;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

//单链表的插入
LinkedList LinkedListInsert(LinkedList L, int i, ElemType x)
{
    Node *pre; // pre为前驱结点
    pre = L;
    int tempi = 0;
    for (tempi = 1; tempi < i; tempi++)
    {
        pre = pre->next; //查找第i个位置的前驱结点
    }
    Node *p; //插入的结点为p
    p = (Node *)malloc(sizeof(Node));
    p->data = x;
    p->next = pre->next;
    pre->next = p;

    return L;
}

// 单链表的删除
LinkedList LinkedListDelete(LinkedList L, ElemType x)
{
    Node *p, *pre; // pre为前驱结点，p为查找的结点
    p = L->next;
    while (p->data != x)
    {
        pre = p;
        p = p->next;
    }
    pre->next = p->next; // 删除操作，将其前驱next指向其后继
    free(p);
    return L;
}

int main()
{
    LinkedList list, start;
    printf("请输入单链表的数据:");
    // list = LinkedListCreatH();
    list = LinkedListCreatT();
    for (start = list->next; start != NULL; start = start->next)
    {
        printf("start-data=%d\n", start->data);
    }

    int i;
    ElemType x;
    printf("请输入插入数据的位置:");
    scanf("%d", &i);
    printf("请输入插入数据的值:");
    scanf("%d", &x);
    LinkedListInsert(list, i, x);
    for (start = list->next; start != NULL; start = start->next)
    {
        printf("start-data=%d\n", start->data);
    }

    printf("请输入要删除的元素的值:");
    scanf("%d", &x);
    LinkedListDelete(list, x);
    for (start = list->next; start != NULL; start = start->next)
    {
        printf("start-data=%d\n", start->data);
    }

    return 0;
}