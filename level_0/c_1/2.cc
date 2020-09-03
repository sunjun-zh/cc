// 动态顺序表
#include <stdio.h>
#include <stdlib.h>

#define ElemType int
#define INIT_SIZE 8

// 定义动态顺序表
typedef struct
{
    /* data */
    ElemType *base; // 存储空间基地址
    int size;       // 当前长度
    int capacity;   // 当前分配的存储容量
} SeqList;

// 检测表是否空
int isempty(SeqList *list)
{
    return list->size == 0;
    // 点运算符(.)的左边操作数是一个结果为结构的表达式
    // 箭头运算符(->)的左边的操作数是一个指向结构体的的指针
}

// 检测表是否满
int isfull(SeqList *list)
{
    return list->size >= list->capacity;
}

// 表初始化
void InitList(SeqList *list)
{
    list->base = (ElemType *)malloc(sizeof(ElemType) * list->capacity);
    list->size = 0;
    list->capacity = INIT_SIZE;
}

// 排序
void sort(SeqList *list)
{
    if (isempty(list))
    {
        return;
    }
    for (int i = 1; i < list->size; i++)
    {
        for (int j = 0; j < list->size - i; j++)
        {
            int temp;
            if (list->base[j] > list->base[j + 1])
            {
                temp = list->base[j];
                list->base[j] = list->base[j + 1];
                list->base[j + 1] = temp;
            }
        }
    }
}

// 头插
void push_front(SeqList *list, ElemType x)
{
    if (isfull(list))
    {
        printf("顺序表已满\n");
    }
    for (int i = list->size; i > 0; i--)
    {
        list->base[i] = list->base[i - 1];
    }
    list->base[0] = x;
    (list->size)++;
}

// 尾插
void push_back(SeqList *list, ElemType x)
{
    if (isfull(list))
    {
        printf("顺序表已满\n");
        return;
    }
    list->base[list->size] = x;
    (list->size)++;
}

// 显示
void show_list(SeqList *list)
{
    if (list->size == 0)
    {
        printf("顺序表为空\n");
        return;
    }
    for (int i = 0; i < list->size; i++)
    {
        printf("%d\n", list->base[i]);
    }
    printf("\n");
}

// 头删
void pop_front(SeqList *list)
{
    if (isempty(list))
    {
        printf("顺序表为空，不能删除\n");
        return;
    }
    for (int i = 0; i < list->size; i++)
    {
        list->base[i] = list->base[i + 1];
    }
    (list->size)--;
}

// 尾删
void pop_back(SeqList *list)
{
    if (isempty(list))
    {
        printf("顺序表为空，不能删除\n");
        return;
    }
    list->size--;
}

// 按位置插
void insert_pos(SeqList *list, ElemType x, int pos)
{
    if (pos < 0 || pos > list->size)
    {
        printf("插入位置不正确\n");
        return;
    }
    if (isempty(list))
    {
        printf("顺序表已满,不能插入\n");
        return;
    }
    for (int i = list->size; i > pos; i--)
    {
        list->base[i] = list->base[i - 1];
    }
    list->base[pos] = x;
    list->size++;
}

// 退出
void quit_system(SeqList *list, int *x)
{
    *x = 0;
}

// 查找
int find(SeqList *list, ElemType x)
{
    for (int i = 0; i < list->size; i++)
    {
        if (list->base[i] == x)
        {
            return i;
        }
    }
    return -1;
}

//求长度
int length(SeqList *list)
{
    return list->size;
}

// 按值插入
void insert_val(SeqList *list, ElemType x)
{
    push_back(list, x);
    sort(list);
}

// 按位置删除
void delete_pos(SeqList *list, int pos)
{
    if (isempty(list))
    {
        printf("顺序表为空，不能删除\n");
        return;
    }
    if (pos < 0 || pos >= list->size)
    {
        printf("删除的位置不正确\n");
        return;
    }
    for (int i = pos; i < list->size; i++)
    {
        list->base[i] = list->base[i + 1];
    }
    list->size--;
}

//按值删除
void delete_val(SeqList *list, ElemType x)
{
    if (isempty(list))
    {
        printf("顺序表为空，不能删除\n");
        return;
    }
    int pos = find(list, x);
    if (pos == -1)
    {
        printf("未找到该数\n");
        return;
    }
    delete_pos(list, pos);
}

// 清空
void clear(SeqList *list)
{
    list->size = 0;
}

// 销毁
void destory(SeqList *list)
{
    list->base = NULL;
}

// 逆序
void reverse(SeqList *list)
{
    for (int i = 0, j = list->size - 1; i < list->size / 2; i++, j--)
    {
        int temp = list->base[i];
        list->base[i] = list->base[j];
        list->base[j] = temp;
    }
}

int main()
{
    SeqList mylist;
    InitList(&mylist);

    int select = 1;
    ElemType Item;
    int pos;
    while (select)
    {
        printf("****************************************************\n");
        printf("*   [1] show_list                 [2] quit_system  *\n");
        printf("*   [3] push_front                [4] push_back    *\n");
        printf("*   [5] pop_front                 [6] pop_back     *\n");
        printf("*   [7] insert_pos                [8] insert_val   *\n");
        printf("*   [9] delete_pos                [10] delete_val  *\n");
        printf("*   [11] find                     [12] length      *\n");
        printf("*   [13] clear                    [14] destory     *\n");
        printf("*   [15] reverse(逆序)            [16] sort(顺序)  *\n");
        printf("****************************************************\n");
        printf("请选择:");

        scanf("%d", &select);
        switch (select)
        {
        case 1:
            show_list(&mylist);
            break;
        case 2:
            quit_system(&mylist, &select);
            break;
        case 3:
            printf("请输入要插入的值(-1结束):>");
            while (scanf("%d", &Item), Item != -1)
            {
                push_front(&mylist, Item);
            }
            break;
        case 4:
            printf("请输入要插入的值(-1结束):>");
            while (scanf("%d", &Item), Item != -1)
            {
                push_back(&mylist, Item);
            }
            break;
        case 5:
            pop_front(&mylist);
            break;
        case 6:
            pop_back(&mylist);
            break;
        case 7:
            printf("请输入要插入的位置:");
            scanf("%d", &pos);
            printf("请输入要插入的值:");
            scanf("%d", &Item);
            insert_pos(&mylist, Item, pos);
            break;
        case 8:
            printf("请输入要插入的数:");
            scanf("%d", &Item);
            insert_val(&mylist, Item);
            break;
        case 9:
            printf("请输入要删的位置:");
            scanf("%d", &pos);
            delete_pos(&mylist, pos);
            break;
        case 10:
            printf("请输入要删的数:");
            scanf("%d", &Item);
            delete_val(&mylist, Item);
            break;
        case 11:
            printf("请输入要查找的数:");
            scanf("%d", &Item);
            pos = find(&mylist, Item);
            if (pos != -1)
            {
                printf("该数为第%d个数\n", pos);
            }
            else
            {
                printf("未找到该数\n");
            }
            break;
        case 12:
            printf("该顺序表长度为:%d\n", length(&mylist));
            break;
        case 13:
            clear(&mylist);
            break;
        case 14:
            destory(&mylist);
            break;
        case 15:
            reverse(&mylist);
            break;
        case 16:
            sort(&mylist);
            break;
        default:
            break;
        }
    }
    return 0;
}