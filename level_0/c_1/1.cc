// 静态顺序表
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10   //定义顺序表的最大容量
#define INITSIZE 10  //定义顺序表的初始容量
#define ElemType int // 定义顺序表存储的类型，可自行设置

// 1. 创建顺序表: 静态分配+动态分配
/*
相同点:内存空间连续, 数据顺序存储

不同点:它们所占内存空间的位置不同, 静态定义一个顺序表, 顺序表所占的内存空间开辟在内存的静态区,
即所谓的函数栈上, 随着函数调用的结束, 这块内存区域会被系统自动回收; 
而动态生成一个顺序表, 顺序表所占的内存空间开辟在内存的动态区, 即所谓的堆内存上, 
这块区域不会随着函数调用的结束被系统自动回收, 而是需要程序员主动去释放它.
*/

// 2. 基本操作: 插入 + 删除  + 按值查找

// 顺序存储的线性表的类型(静态分配)
typedef struct
{
    /* data */
    ElemType data[MAXSIZE]; //存放线性表的数组
    int length;             //length是线性表的长度
} SeqList;

// 顺序表的初始化
SeqList SeqListInit()
{
    SeqList L;    //定义一个顺序表
    L.length = 0; //顺序表的长度为0
    return L;     //返回空顺序表
}

// 顺序表的建立
SeqList SeqListCreate(SeqList L)
{
    ElemType x;
    scanf("%d", &x);
    while (x != -1) // 存储顺序表的元素 ctrl+d
    {

        L.data[L.length] = x;
        L.length++;
        scanf("%d", &x);
    }
    return L;
}

// 顺序表的插入
SeqList SeqListInsert(SeqList L, int i, ElemType x)
{ // 在顺序表中的第i个位置插入元素x
    // 判断数据插入的有效性
    if (L.length == MAXSIZE)
    {
        printf("表已经满了\n");
    }
    else if (i < 1 || i > L.length)
    {
        printf("插入位置错误\n");
    }
    int j;
    // 第i个位置元素逐个后移
    for (j = L.length - 1; j >= i - 1; j--)
    {
        L.data[j + 1] = L.data[j];
    }
    L.data[i - 1] = x;
    L.length++;
    return L;
}

// 按位查找
void SeqListGetElem(SeqList L, int i)
{
    if (i < 1 || i > L.length)
    {
        printf("没有查找到值\n");
    }
    else
    {
        /* code */
        printf("查找的值:%d\n", L.data[i - 1]);
    }
}

//按值查找
void SeqListLocateElem(SeqList L, ElemType x)
{
    int i = 0;
    while ((i <= L.length && L.data[i] != x))
    {
        i++;
    }

    if (i <= L.length)
    {

        printf("查找位置:%d\n", i + 1);
    }
    else
    {
        printf("没有查找到位置\n");
    }
}

//删除
SeqList SeqListDelete(SeqList L, int i)
{
    if (i < 1 || i > L.length)
    {
        printf("删除位置错误\n");
    }
    int j;
    // 将第i个位置之后的元素前移
    for (j = i - 1; j < L.length; j++)
    {
        L.data[j] = L.data[j + 1];
    }
    L.length--;
    return L;
}

void printList(SeqList seqlist)
{
    int i;
    for (i = 0; i < seqlist.length; i++)
    {
        printf("seqlist.data[%d] = %d\n", i, seqlist.data[i]);
    }
    printf("--------\n");
}

int main()
{
    SeqList seqlist;
    seqlist = SeqListInit();
    int i;
    ElemType x;
    printf("创建一个顺序表，请输入顺序表的元素:");
    seqlist = SeqListCreate(seqlist);
    printList(seqlist);

    printf("请输入要查找的元素的位置:\n");
    scanf("%d", &i); // scanf("%d", &x)
    printf("此时i=%d\n", i);
    SeqListGetElem(seqlist, i);
    printf("\n");

    printf("请输入要查找的元素的值:\n");
    scanf("%d", &x);
    printf("此时x=%d\n", x);
    SeqListLocateElem(seqlist, x);
    printf("\n");

    printf("请输入插入元素位置:");
    scanf("%d", &i);
    printf("请输入插入元素值:");
    scanf("%d", &x);
    seqlist = SeqListInsert(seqlist, i, x);
    printList(seqlist);
    printf("\n");

    printf("请输入删除元素的位置:");
    scanf("%d", &i);
    seqlist = SeqListDelete(seqlist, i);
    printList(seqlist);

    return 0;
}
