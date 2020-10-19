#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;

//1.判断字符数组A中输入于输出序列是否是合法序列. 如是，返回true; 若不是，返回false
/*
   I O 分别表示入栈和出栈操作 
*/
bool Judge(char A[])
{
    int i = 0; //i为下标，j和k分别为字符I和O的个数
    int j = 0;
    int k = 0;
    while (A[i] != '\0')
    { //未到字符数组尾
        switch (A[i])
        {
        case 'I':
            j++; //入栈次数增1
            break;
        case 'O':
            k++;
            if (k > j)
            {
                printf("序列非法\n");
                exit(0);
            }
        }
        i++; //指针i均后移
    }
    if (j != k)
    {
        printf("序列非法\n");
        return false;
    }
    else
    {
        printf("序列合法\n");
        return true;
    }
}

//2.L是带头结点的n个元素单链表，本算法判断链表是否是中心对称; 入xyx xyyx
int dc(LinkList L, int n)
{
    int i;
    char s[n / 2]; //s为字符栈
    p = L->next;   //p是链表的工作指针，指向待处理的当前元素

    for (i = 0; i < n / 2; i++)
    { //链表前一半元素进栈
        s[i] = p->data;
        p = p->next;
    }
    i--;            //恢复最后的i值
    if (n % 2 == 1) //若n为奇数，后移动中心结点
        p = p->next;
    while (p != NULL && s[i] == p->data)
    {        //检测是否中心对称
        i--; //i充当栈顶指针
        p = p->next;
    }
    if (i == -1)  //栈为空栈
        return 1; //链表中心对称
    else
        return 0; //链表不中心对称
}


//3.两个栈共享向量空间，将两个栈的栈底设在向量两端，初始时，s1栈顶指针为-1
//s2栈顶指针为maxsize。两个栈顶指针相邻为栈满.
/*
    入栈判满，出栈判空
*/
#define maxsize 100
#define elemtp int //假设元素类型为整型
typedef struct{
    elemtp stack[maxsize]; //栈空间
    int top[2]; //top为两个栈顶指针
} stk;
stk s; //s是如上定义的结构类型变量，为全局变量
//入栈操作
int push(int i, Elemtype x)
{
    //入栈操作。i为栈号， i=0表示左边的s1栈, i=1表示右边s2栈,x是入栈元素
    //入栈成功返回1, 否则返回0
    if(i<0||i>1){
        printf("栈号输入不对");
        exit(0);
    }
    if(s.top[-1]-s.top[0]==1){
        printf("栈已满\n");
        return 0;
    }
    switch(i){
        case 0:
            s.stack[++s.top[0]]=x;
            return 1;
            break;
        case 1:
            s.stack[--s.top[1]] = x;
            return 1;
        }
}

//退栈操作
elemtp pop(int i){
    //成功则返回栈元素, 否则返回-1
    if(i<0||i>1){
        printf("栈号输入错误\n");
        exit(0);
    }
    switch(i){
        case 0:
            if(s.top[0]==-1){
                printf("栈空\n");
                return -1;
            }else{
                return s.stack[s.top[0]--];
            }
        case 1:
            if(s.top[-1]==maxsize){
                printf("栈空\n");
                return -1;
            }else{
                return s.stack[s.top[1]++];
            }
    }
}
