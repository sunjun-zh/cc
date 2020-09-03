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


// 线性表的合并
/*
已知两个集合 A 和 B ，现要求一个新的集合 A=A U B ，例如，设
A=（7，5，3，11）
B=（2，6，3）
合并后，A=（7，5，3，11，2，6）


void MergeList(SqList &LA, SqList LB)
{
    int m = ListLength(LA); 
    int n = ListLength(LB);
    for(i=1;i<=n;i++){
        GetElem(LB, i, e); // 取LB中第i个元素赋值给e
        if(!LocateElem(LA, e)){
            ListInsert(LA, ++m, e); //将e插入la的最后
        }
    }
}
*/


// 有序表的合并
/*
有序集合是指集合中的元素有序排列。
已知两个有序集合 A 和 B ，数据元素按值非递减有序排列，现要求一个新的集合 C = A U B ，使集合 C 中的数据元素仍按值非递减有序排列。例如，设
A=（3，5，8，11）
B=（2，6，8，9，11，15，20）
则，C=（2，3，5，6，8，9，11，11，15，20）

1. 顺序表
void MergeList_Sq(SqList &LA, SqList LB, SqList &LC){
    LC.length = LA.length+LB.length; // 新表的长度
    LC.elem = new ElemType[LC.length]; // 为新表分配一个数组空间
    pc = LC.elem; //指针pc指向新表的第一个元素
    pa = LA.elem;
    pb = LB.elem;
    pa_last = LA.elem + LA.length-1; // 指针pa_last指向la的最后一个元素
    pb_last = LB.elem + LB.length-1; // 指针pb_last指向lb的最后一个元素
    while((pa<=pa_last)&&(pb<=pb_last)){
        if(*pa<=*pb)
            *pc++=*pa++; // 依次摘取两表中较小的结点插入到lc最后
        else
            *pc++=*pb++;
    }
    while(pa<pa_last) *pc++=*pa++; //la已到达表尾，依次将la的剩余元素插入到lc的最后
    while(pb<pb_last) *pc++=*pb++; //lb已到达表尾，依次将lb的剩余元素插入到lc的最后
}
2.链表
void MergeList_L(LinkList &La, LinkList &Lc,LinkList &Lc)
{
    pa = La->next;
    pb = Lb->next;
    pc=Lc=La; //用la的头结点作为lc的头结点
    while(pa&&pb){
        if(pa->data <= pb->data)
        {
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }
        else{
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
    }
    pc->next=pa?pa:pb; 插入剩余段
    delete Lb; //释放lb的头结点
}
*/
// 一
int main(){

    return 0;
}
