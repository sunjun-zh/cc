// 双链表
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

// 定义双链表结点类型
struct DLinkList
{
    /* data */
    ElemType data;
    struct DLinkList *prior; // 结点的前驱指针
    struct DLinkList *next;  // 结点的后驱指针
};

// 初始化结点
struct DLinkList *createList()
{
    // 创建一个头结点
    struct DLinkList *headNode = (struct DLinkList *)malloc(sizeof(struct DLinkList));
    // 初始化头指针 尾指针都指向自身
    headNode->prior = headNode;
    headNode->next = headNode;
    return headNode;
}

// 创建新结点
struct DLinkList *createNode(int data)
{
    struct DLinkList *newNode = (struct DLinkList *)malloc(sizeof(struct DLinkList));
    newNode->data = data;
    newNode->prior = NULL;
    newNode->next = NULL;
    return newNode;
}

// 插入新的元素--头插
void insertNodeByHead(struct DLinkList *headNode, int data)
{
    // 创建一个新的结点
    struct DLinkList *newNode = createNode(data);
    newNode->prior = headNode;
    newNode->next = headNode->next;
    headNode->next->prior = newNode;
    headNode->next = newNode;
}

// 插入新的元素 -- 尾插
void insertNodeByNext(struct DLinkList *headNode, int data)
{
    // 创建一个新的结点
    struct DLinkList *newNode = createNode(data);
    // 首先找到最后一个结点的位置
    struct DLinkList *lastNode = headNode;
    while (lastNode->next != headNode)
    {
        lastNode = lastNode->next;
    }
    //调整四个指针
    headNode->prior = newNode;
    newNode->next = newNode;
    lastNode->next = newNode;
    newNode->prior = lastNode;
}

// 删除指定元素
void SpecifyLocationToDelete(struct DLinkList *headNode, int posData)
{
    struct DLinkList *posNode = headNode->next; // 指定结点指针
    struct DLinkList *postNodeprior = headNode; //指定结点前一个结点的指针

    // 找到指定位置
    while (posNode->data != posData)
    {
        postNodeprior = posNode;
        posNode = postNodeprior->next;
        // 如果没有找到特殊处理
        if (posNode->next == headNode)
        {
            printf("不存在指定位置，无法删除\n");
            return;
        }
    }
    postNodeprior->next = posNode->next;
    posNode->next->prior = postNodeprior;
    free(posNode); //删除后，释放空间
}

// 查找指定元素 -- 从表头
void searchSpecifiedElement(struct DLinkList *headNode, int posData)
{
    struct DLinkList *posNode = headNode->next; //指定结点指针
    struct DLinkList *posNodeprior = headNode;  //指定结点前一个结点指针

    while (posNode->data != posData)
    {
        posNodeprior = posNode;
        posNode = posNodeprior->next;
        // 如果没有找到特殊处理
        if (posNode->next == headNode)
        {
            printf("不存在该元素\n");
            return;
        }
    }
    printf("该元素存在\n");
}

void printList(struct DLinkList *headNode)
{
    // 从第二个结点开始打印，表头不含数据
    struct DLinkList *pMove = headNode->next;
    while (pMove != headNode)
    {
        printf("%d ", pMove->data);
        pMove = pMove->next;
    }
    printf("\n");
}

int main()
{
    struct DLinkList *headNode = createList();
    insertNodeByNext(headNode, 20);
    insertNodeByNext(headNode, 30);
    insertNodeByNext(headNode, 40);
    printList(headNode);

    return 0;
}