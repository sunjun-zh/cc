#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;

typedef struct LNode
{
    /* data */
    Elemtype data;
    struct LNode *next;
} LNode, *LinkList;

// 1.设计一个递归算法，删除不带头结点的单链表L中所有值为x的结点
/* 
递归模型:
终止条件
递归主体
*/
void Del_x(Linklist &L, ElemType x)
{
    LNode *p;      //p指向待删除结点
    if (L == NULL) //递归出口
        return;
    if (L->data == x)
    {
        p = L; // 删除*L，并让L指向下一个结点
        L = L->next;
        free(p);
        Del_x(L, x); //递归调用
    }
    else
    {
        Del_x(L->next, x);
    }
}

//2.带头结点的单链表L中，删除所有值为x的结点，并释放空间（假设值为x的结点不唯一）
//2-1 用p从头至尾扫描单链表
void Del_x_2_1(LinkList &L, Elemtype x)
{
    // L为带头结点的单链表
    LNode *p = L->next, *pre = L, *q; // 置p和pre的初始值
    while (p != NULL)
    {
        if (p->data == x)
        {
            q = p; //q指向该结点
            p = p->next;
            pre->next = p; //删除*q结点
            free(q);
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
}

//2-2 尾插法建立单链表
void Del_x_2_2(LinkList &L, Elemtype x)
{
    LNode *p = L->next, *r = L, *q; //r指向尾结点，其初值为头结点
    while (p != NULL)
    {
        if (p->data != x)
        { //*p结点值不为x时将其链到L尾部
            r->next = p;
            r = p;
            p = p->next;
        }
        else
        {
            q = p;
            p = p->next;
            free(q);
        }
    }
    r->next = NULL;
}

// 3.设L为带头结点的单链表，编写算法实现从尾至头反向输出每个结点的值
void R_Print(LinkList L)
{
    if (L->next != NULL)
    {
        R_Print(L->next); //递归
    }
    print(L->data);
TODO:
    不懂
}

// 4.带头结点的单链表L，删除一个最小值结点(最小值结点唯一)
Linklist Delete_min(LinkList &L)
{
    LNode *pre = L, *p = pre->next; // p为工作指针，pre指向其前驱
    LNode *minpre = pre, *minp = p; // 保存最小值结点及其前驱
    while (!p = NULL)
    {
        if (p->data < minp->data)
        {
            minp = p; //找到比之前找到的最小值结点更小的结点
            minpre = pre;
        }
        pre = p; //继续扫描下一个结点
        p = p->next;
    }
    minp->next = minp->next; //删除最小值结点
TODO:
    怎么删除？是否会出现断链
    free(minp);
    return L;
}

// 5.将带头结点的单链表就地逆置
// 5-1 将头结点摘下，然后从第一结点开始,依次前插入到头结点的后面
LinkList Reverse_5_1(LinkList L)
{
    LNode *p, *r;   //p为工作指针，r为p的后继， 以防止断链
    p = L->next;    //从第一个元素结点开始
    L->next = NULL; // 先将头结点L的next域置为NULL
    while (p != NULL)
    {
        r = p->next;
        p->next = L->next; //将p结点插入到头结点之后 TODO:不明白就画图，非常容易理解
        L->next = p;
        p = r;
    }
}

//5-2 将 pre p r的next都指向原前驱结点
LinkList Reverse_5_2(LinkList L)
{
    LNode *pre, *p = L->next, *r = p->next;
    p->next = NULL; //处理第一个结点
    while (r != NULL)
    { //r为空，则说明p为最后一个结点
        pre = p;
        p = r;
        r = r->next;
        p->next = pre; //指针反转
    }
    L->next = p;
    return L;
}

// 6.有一个带头结点的单链表L，设计一个算法使其元素递增有序
void Sort(LinkList &L)
{
    LNode *p = L->next, *pre;
    LNode *r = p->next;
    p->next = NULL; //构造只含有一个数据结点的有序表
    p = r;
    while (p != NULL)
    {
        r = p->next; //保存*p的后继结点指针
        pre = L;
        while (pre->next != NULL && pre->next->data < p->data)
            pre = pre->next; // 在有序表中查找插入*p的前驱结点*pre
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
}

//7.给定两个值，删除一个带头结点的无序单链表中值介于之间的所有值
void RangeDelete(LinkList &L, int min, int max)
{
    LNode *pr = L, *p = L->next; //p是检测指针,pr是前驱
    while (p != NULL)
    {
        if (p->data > min && p->data < max)
        {
            pr->data = p->data;
            free(p);
            p = pr->data;
        }
        else
        {
            pr = p;
            p = p->next;
        }
    }
}

//8.给定两个单链表，找出公共结点
/*
解题思路: 先分别遍历两个链表得到他们的长度,并求出两个长度之差。
在长链表上先遍历长度之差个结点后，再同步遍历两个链表，直到找到相同的结点，或一直到链表结束
*/
LinkList Search_lst_Common(LinkList L1, LinkList L2)
{
    int len1 = Length(L1), len2 = Length(L2);
    LinkList longlist, shortList;
    if (len1 > len2)
    {
        longlist = L1->next;
        shortList = L2->next;
        dist = len1 - len2; //表长之差
    }
    else
    {
        longlist = L2->next;
        shortList = L1->next;
        dist = len2 - len1; //表长之差
    }
    while (dist--) // 表长的链表先遍历到第dist个结点，然后同步
        longlist = longlist->next;
    while (longlist != NULL)
    { //同步寻找共同结点
        if (longlist == shortlist)
            return longlist;
        else
        {
            longlist = longlist->next;
            shortlist = shortlist->next;
        }
    }
    return NULL;
}

//9.给定一个带头结点的单链表，设head为头指针；按递增次序输出单链表中各结点的数据元素，
//并释放结点所占的存储空间
void Min_Delete(LinkList &head)
{
    while (head->next != NULL) //循环到仅剩头结点
    {
        pre = head;    //pre为元素最小值结点的前驱结点的指针
        p = pre->next; //p为工作指针
        while (p->next != NULL)
        {
            if (p->next->data < pre->next->data)
            {
                pre = p; //记住当前最小值结点的前驱
                p = p->next;
            }
        }
        print(pre->next->data);
        u = pre->next;
        pre->next = u->next;
        free(u);
    }
    free(head); //释放头结点
}

//10.将表A中的结点按序号的奇偶性分解到表A或表B中
LinkList DisCreat_1(LinkList &A)
{
    int i = 0;                                    //记录表a中结点的序号
    LinkList B = (LinkList)malloc(sizeof(LNode)); // 创建B表表头
    B->next = NULL;                               //b表初始化
    LNode *ra = A, *rb = B;                       //ra和rb将分别指向将创建A表和B表的尾结点

    p = A->next;    //p为链表工作指针，指向待分解的结点
    A->next = NULL; //置空新的a表
    while (p != NULL)
    {
        i++;
        if (i % 2 == 0)
        {
            rb->next = p; //在b表尾插入新结点
            rb = p;
        }
        else
        {
            ra->next = p;
            ra = p;
        }
        p = p->next; //将p恢复为指向新的待处理结点
    }
    ra->next = NULL;
    rb->next = NULL;
    return B;
}

//11.将线性表c拆分为两个线性表
LinkList DisCreat_2(LinkList &A)
{
    LinkList B = (LinkList)malloc(sizeof(LNode)); //创建b表表头
    B->next = NULL;                               //b表的初始化
    LNode *p = A->next, *q;                       //p为工作指针
    LNode *ra = A;                                //ra始终指向A的尾结点
    while (p != NULL)
    {
        ra->next = p; // 将*p链到a的表尾
        ra = p;
        p = p->next;
        q = p->next;       //头插后，*p将断链，因此用q记忆*p的后继
        p->next = B->next; //将*p插入到B的前端
        B->next = p;
        p = q;
    }
    ra->next = NULL; //a尾结点的next域置空
    return B;
}

//12.L是递增有序的单链表，本算法删除表中数值相同的元素
void Del_Same(LinkList &L)
{
    LNode *p = L->next, *q; //p为扫描工作指针
    if (p == NULL)
        return;
    while (p->next != NULL)
    {
        q = p->next;            //q指向*p的后继结点
        if (p->data == q->data) //找到重复置的结点
        {
            p->next = q->next; //释放*q结点
            free(q);
        }
    }
}

//13.合并两个递增有序链表(带头结点),并使合并后的链表递减排序
void MergeList(LinkList &La, LinkList &Lb)
{
    LNode *r, *pa = La->next, *pb = Lb->next; //分别使表la和lb的工作指针
    La->next = NULL;                          //la作为结果链表的头指针,先将结果链表初始化为空
    while (pa && pb)
    {
        if (pa->data <= pb->data)
        {
            r = pa->next; //r暂存pa的后继结点指针
            pa->next = La->next;
            La->next = pa; //将pa结点链于结果表中，同时逆置(头插法)
            pa = r;        //恢复pa为当前待比较结点
        }
        else
        {
            r = pb->next; //r暂存pb的后继结点指针
            pb->next = La->next;
            La->next = pb; //将pb结点链于结果表中，同时逆置
            pb = r;        //恢复pb为当前待比较结点
        }
    }

    if (pa)
        pb = pa; //通常情况下会剩下一个链表非空，处理剩下的部分

    while (pb)
    {                 //处理剩下的一个非空链表
        r = pb->next; //依次插入到La中(头插法)
        pb->next = La->next;
        La->next = pb;
        pb = r;
    }
    free(Lb);
}

// 14.本算法产生单链表A和B的公共元素的单链表C
void Get_Common(LinkList A, LinkList B)
{
    LNode *p = A->next, *q = B->next, *r, *s;
    LinkList C = (LinkList)malloc(sizeof(LNode)); //建立表C
    r = C;                                        //r始终指向C的尾结点
    while (p != NULL && q != NULL)                //循环跳出条件
    {
        if (p->data < q->data)
            p = p->next; //若A的当前元素较小，后移指针
        else if (p->data > q->data)
            q = q->next; //若B的当前元素较小，后移指针
        else
        {
            //找到公共元素结点
            s = (LNode *)malloc(sizeof(LNode));
            s->data = p->data; //复制产生结点*s
            r->next = s;       //将*s链接到c上(尾插法)
            r = s;
            p = p->next; //表a和b继续向后扫描
            q = q->next;
        }
    }
}

// 15.已知两个链表A和B分别表示两个集合，其元素递增排列。
//求A与B的交集，并存放于A链表中
LinkList union(LinkList &la, LinkList &lb)
{
    LNode *pa = la->next; //设工作指针分别为pa和pb
    LNode *pb = lb->next;
    LNode *pc = la;

    while (pa && pb)
    {
        if (pa->data == pb->data)
        {                  //交集并入结果表中
            pc->next = pa; //A中结点链接到结果表
            pc = pa;
            pa = pa->next;
            u = pb; //B中结点释放  TODO:中间变量，应该定义数据类型
            pb = pb->next;
            free(u);
        }
        else if (pa->data < pb->data) //若A中当前结点值小于B中当前结点的值
        {
            u = pa;
            pa = pa->next; //后移指针
            free(u);       //释放a中当前结点
        }
        else
        {
            u = pb;
            pb = pb->next;
            free(u);
        }
    }

    while (pa)
    {
        u = pa;
        pa = pa->next;
        free(u);
    }
    while (pb)
    {
        u = pb;
        pb = pb->next;
        free(u);
    }
    pc->next = NULL;
    free(lb);
    return la;
};

// 16.A和B分别是数据域为整数的单链表，本算法判断B是否是A的子序列
int Pattern(LinkList A, LinkList B)
{
    LNode *p = A;   //p为A链表的工作指针，本题假定A和B均无头结点
    LNode *pre = p; //pre记住每趟比较中A链表的开始结点
    LNode *q = B;   //q是B链表的工作指针
    while (p && q)
    {
        if (p->data == q->data)
        {
            p = p->next;
            q = q->next;
        }
        else
        {
            pre = pre->next;
            p = pre; //A链表新的开始比较结点
            q = B;   //q从B链表第一个结点开始
        }
    }
    if (q == NULL) //B已经比较结束
        return 1;  //说明B是A的子序列
    else
        return 0; //说明B不是A的子序列
}

typedef struct DuLNode
{
    Elemtype data;                //结点的数据域
    struct DuLNode *prior, *next; //结点的指针域

} DuLNode, *DuLinkList;

// 17.设计一个算法用于判断带头结点的循环双链表是否对称
int Symmetry(DuLinkList L)
{
    DuLNode *p = L->next, *q = L->prior; //两头工作指针
    while (p != q && q->data)
    {
        if (p->data == q->data)
        {
            p = p->next;
            q = q->next;
        }
        else
            return 0;
    }
    return 1; //比较结束后返回1
}

//18.将循环链表h2链接到循环链表h1之后，使之保持循环链表的形式
LinkList Link(LinkList &h1, LinkList &h2)
{
    LNode *p, *q; //分别指向两个链表的尾结点
    p = h1;
    while (p->next != h1) //寻找h1的尾结点
        p = p->next;
    q = h2;
    while (q->next != h2) //寻找h2的尾结点
        q = q->next;
    p->next = h2; //将h2链接到h1之后
    q->next = h1; //令h2的尾结点指向h1
    return h1;
}

//19.实现每次删除循环单链表中最小元素，直到链表空为止
void Del_all(LinkList &L)
{
    LNode *p, *pre, *minp, *minpre; //minp 指向最小值的结点 minpre指向其前驱结点
    while (L->next != L)
    {
        p = L->next;
        pre = L;
        minp = p;
        minpre = pre;
        while (p != L)
        {
            if (p->data < minp->data)
            { //找到值更小的结点
                minp = p;
                minpre = pre;
            }
            pre = p; //查找下一个结点
            p = p->next;
        }
        printf("%d", minp->data); //输出最小值结点元素
        minpre->next = minp->next;
        free(minp);
    }
    free(L); //释放头结点
}


// 20-23 TODO:大题


