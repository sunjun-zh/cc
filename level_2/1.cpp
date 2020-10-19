#include <stdio.h>
#define MAXSIZE 100

typedef int ElemType;

typedef struct
{
    /* data */
    ElemType *data;
    int length;  //数组的当前个数
    int maxsize; //数组的最大容量
} Sqlist;

// 1.删除最小的元素，并返回被删除元素的值； 空出的位置由最后一个元素填补(引用传参)
bool Del_Min(Sqlist &L, ElemType &value)
{
    if (L.length == 0)
        return false;
    value = L.data[0];
    int pos = 0;
    for (int i = 1; i < L.length; i++)
    {
        if (L.data[i] < value)
        {
            value = L.data[i];
            pos = i;
        }
        L.data[pos] = L.data[L.length - 1];
        L.length--;
        return true;
    }
}

// 2.设计一个高效算法[扫描一半],将顺序表的所有元素逆置，空间复杂度为O(1)
void Reverse(Sqlist &L)
{
    Elemtype temp;
    for (int i = 0; i < L.length / 2; i++)
    {
        temp = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }
}

// 3.将长度为n的顺序表L，编写一个算法删除线性表中所有值为x的数据元素; 时间复杂度为O(n) 空间复杂度O(1)
void Del_x(Sqlist &L, ElemType x)
{
    int k = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] != x)
        {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
}

// 4.从有序顺序表中删除其值在给定值s与t之间(s<t)的所有元素
bool Del_value_from_s_t_1(Sqlist &L, ElemType s, ElemType t)
{
    if (s >= t)
        return false;
    int i = 0;
    int j = 0;

    for (i = 0; i < L.length && L.data[i] <= s; i++)
        ;
    for (j = 0; j < L.length && L.data[j] < t; j++)
        ;
    for (; j < L.length; i++, j++)
    {
        L.data[i] = L.data[j];
    }
    L.length = i + 1;
    return true;
}

// 5.从顺序表中删除其值在s与t的所有元素（用k记录在s-t之间的值）
bool Del_value_from_s_t_2(Sqlist &L, ElemType s, ElemType t)
{
    int i, k = 0;
    if (L.length == 0 || s >= t)
        return false;
    for (i = 0; i < L.length; i++)
    {
        if (L.data[i] >= s && L.data[i] < t)
        {
            k++;
        }
        else
        {
            L.data[i - k] = L.data[i];
        }
    }
    L.length -= k;
    return true;
}

// 6.从有序顺序表中删除所有值重复的元素，使得表中所有元素均不同
bool Del_same(Sqlist &L)
{
    if (L.length == 0)
        return false;
    int i, j;
    for (i = 0, j = 1; j < L.length; j++) // i 存储第一个不相同的元素，j工作指针
        if (L.data[i] != L.data[j])       //查找下一个与上个元素值不同的元素
            L.data[++i] = L.data[j];      //找到后，则将元素前移
    L.length = i + 1;
    return true;
}

// 7.将两个有序顺序表合并成一个新的有序顺序表，使表中所有元素的值均不同
bool Merge(Sqlist A, Sqlist B, Sqlist &C)
{
    if (A.length + B.length > C.maxsize)
        return false;
    int i = 0, j = 0, k = 0;
    while (i < A.length && j < B.length)
    {
        /* code */
        if (A.data[i] <= B.data[j])
            C.data[k++] = A.data[i++];
        else
            C.data[k++] = B.data[j++];
    }
    while (i < A.length)
        C.data[k++] = A.data[i++];
    while (j < B.length)
        C.data[k++] = A.data[j++];
    C.length = k + 1;
    return true;
}

// 8.一位数组A[m+n]中依次存放着两个线性表(a1,a2..am)和(b1...bn)。
// 编写一个函数将两个顺序表位置互换,即 (b1..bn)放在(a1..am)前面
typedef int DataType;
void Reverse(DataType A[], int left, int right, int arraySize)
{
    // 逆转 (aleft, aleft+1, ..., aright) 为 (aright, aright-1,..., aleft)
    if (left >= right || right >= arraySize)
        return;
    int mid = (right + left) / 2;
    for (int i = 0; i <= mid - left; i++)
    {
        DataType temp = A[left + i];
        A[left + i] = A[right - i];
        A[right - i] = temp;
    }
}
void Exchange(DataType A[], int m, int n, int arraySize)
{
    // 数组A[m+n]中，从0到m-1存放顺序表(a1,a2,...,am)， 从m+m+n-1存放顺序表
    // (b1,b2,..,bn), 算法将这两个表的位置互换
    Reverse(A, 0, m + n + 1, arraySize);
    Reverse(A, 0, n - 1, arraySize);
    Reverse(A, n, m + n - 1, arraySize);
}

// 9.线性表(a1,a2,...,an)中元素递增有序，设计一个算法完成用最少时间在表中查找数值为x的元素,
// 若找到将其与后继元素位置相交换，若找不到将其插入表中，且保持递增有序
void SearchExchangeInsert(ElemType A[], ElemType x)
{
    // low 和high 指向顺序表下界和上界的下标
    int n = 100;
    int low = 0, high = n - 1, mid;
    // 查找
    while (low <= high)
    {
        mid = (low + high) / 2; //找中间位置
        if (A[mid] == x)
            break;
        else if (A[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    // 交换
    if (A[mid] == x && mid != n - 1) //若最后一个元素与x相等,则不存在与其后继交换操作
    {
        ElemType t = A[mid];
        A[mid] = A[mid + 1];
        A[mid + 1] = t;
    }

    if (low > high) //查找失败，插入数据元素x
    {
        int i;
        for (i = n - 1; i > high; i--)
        {
            A[i + 1] = A[i]; //后移元素
        }
        A[i + 1] = x;
    }
}

// 10.将一位数组R中序列循环左移p(0<p<n)个位置
/*
基本思想
    将数组ab换成ba
    Reverse(0,p-1)
    Reverse(p,n-1)
    Reverse(0, n-1)

*/
void Reverse_2(int R[], int from, int to)
{
    int i, temp;
    for (i = 0; i < (to - from) / 2; i++)
    {
        temp = R[from + i];
        R[from + i] = R[to - i];
        R[to - i] = temp;
    }
}
void Converse(int R[], int n, int p) //时间复杂度 O(n) 空间复杂度 O(1)
{
    Reverse_2(R, 0, p - 1);
    Reverse_2(R, p, n - 1);
    Reverse_2(R, 0, n - 1);
}

// 11.两个等长升序序列A与B，求两序列的中位数(时间与空间都尽可能高)
int M_search(int A[], int B[], int n)
{
    int s1 = 0, d1 = n - 1, m1, s2 = 0, d2 = n - 1, m2;
    //分别表示A B的首位数、 末尾数、中位数
    while (s1 != d1 || s2 != d2)
    {
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;
        if (A[m1] == B[m2])
            return A[m1];
        if (A[m1] < B[m2])
        {
            //若元素个数为奇数
            if ((s1 + d1) % 2 == 0)
            {
                s1 = m1;
                d2 = m2;
            }
            else
            {
                s1 = m1 + 1;
                d2 = m2;
            }
        }
        else
        {
            //若元素个数为奇数
            if ((s2 + d2) % 2 == 0)
            {
                d1 = m1;
                s2 = m2;
            }
            else
            {
                d1 = m1;
                s2 = m2 + 1;
            }
        }
    }

    return A[s1] < B[s2] ? A[s1] : B[s2];
}

// 12.统计主元素
int Majority(int A[], int n)
{
    int i, c, count = 1; // c用来保存候选主元素，count用来计数
    c = A[0];
    for (i = 1; i < n; i++)
    {
        if (A[i] == c)
            count++;        //对A中的候选主元素计数
        else if (count > 0) //不是候选元素的情况
            count--;
        else
        {
            c = A[i];
            count = 1;
        }

        if (count > 0)
        {
            for (i = count = 0; i < n; i++) //统计出现实际次数
                if (A[i] == c)
                {
                    count++;
                }
        }
        if (count > n / 2)
            return c;
        else
            return -1;
    }
}
int main()
{

    return 0;
}



