//顺序表
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
typedef char ElemType;

// 顺序表类型定义--动态数组定义方式
typedef struct
{
    ElemType *elem; // 存放元素
    int length;     // 实际长度;（逻辑位序和物理位序相差1）
} SqList;

/*
顺序表类型定义--静态数组定义方式
typedef struct
{
    ElemType elem[MAXSIZE];  // 存放元素
    int length;             // 实际长度;（逻辑位序和物理位序相差1）
} SqList;
*/

//线性表的初始化(参数用引用型--对形参进行操作，就相当于对实参进行操作)
//构造一个空的顺序表L
Status InitList_Sq(SqList &L)
{
    // L.elem = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE)
    L.elem = new ElemType[MAXSIZE]; // 为顺序表分配空间

    if (!L.elem) // 存储分配失败
        exit(OVERFLOW);
    L.length = 0; //空表长度为0
    return OK;
}

// 销毁线性表
void DestroyList(SqList &L)
{
    if (L.elem)
        delete L.elem; // 释放存储空间 free(指针)
}

// 清空线性表
void ClearList(SqList &L)
{
    L.length = 0; // 将线性表的长度置为0
}

// 求线性表长度
int GetLength(SqList L)
{
    return (L.length);
}
// 判断是否为空
int IsEmpty(SqList L)
{
    if (L.length == 0)
        return 1;
    else
        return 0;
}

// 取值--根据位置i (随机存取) O(1)
int GetElem(SqList L, int i, ElemType &e)
{
    // 判断位置是否合法
    if (i < 1 || i > L.length)
        return ERROR;
    // 逻辑位置与存储位置相差1
    e = L.elem[i - 1];
    return OK;
}

// 按值查找 -- 顺序查找(从头到尾) O(n)
int LocateElem(SqList L, ElemType e)
{
    int i;
    for (i = 0; i < L.length; i++)
    {
        if (L.elem[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}

// 插入 O(n)
int ListInsert_Sq(SqList &L, int i, ElemType e)
{
    // 位置是否合法
    if (i < 1 || i > L.length + 1)
        return ERROR;

    // 存储空间是否已满
    if (L.length == MAXSIZE)
        return ERROR;

    // 后移
    int j;
    for (j = L.length - 1; j >= i - 1; j--)
        L.elem[j + 1] = L.elem[j];
    L.elem[i - 1] = e;
    L.length++;
    return 0;
}

// 删除 
int DeleteElem_Sq(SqList &L, int i)
{
    // 判断位置i
    if (i < 1 || i > L.length)
        return ERROR;
    int j;
    for (j = i; j <= L.length; j++)
        L.elem[j - 1] = L.elem[j];
    L.length--;

    return OK;
}

int main()
{
    return 0;
}