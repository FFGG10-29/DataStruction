#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {
    ElemType data;      // 存储数据的字段
    struct LNode* next; // 指向下一个结点的指针
} LNode, *LinkList;

// 初始化链表（带头结点）
bool InitList(LinkList& L) {
    L = (LinkList)malloc(sizeof(LNode)); // 创建头结点
    if (L == NULL) {
        return false; // 内存分配失败
    }
    L->next = NULL; // 头结点的next指针初始化为空
    return true;
}

// 在链表的第i个位置插入元素e
bool InsertList(LinkList& L, int i, ElemType e) {
    if (i < 1) {
        return false; // 插入位置小于 1，插入失败
    }
    LNode* p = L;
    int j = 0;
    while (p != NULL && j < i - 1) {
        p = p->next; // 找到要插入位置的前一个节点，指针p向后移动
        j++;
    }
    if (p == NULL) {
        return false; // 插入位置超出链表范围，插入失败
    }
    LNode* s = (LinkList)malloc(sizeof(LNode)); // 创建新节点s
    if (s == NULL) {
        return false; // 内存分配失败
    }
    s->data = e;       // 将元素e赋值给新节点s的data字段
    s->next = p->next; // 新节点s的next指针指向原来位置i的节点
    p->next = s; // 前一个节点的next指针指向新节点s，将其插入链表中
    return true;
}

// 删除链表中值为x的节点
bool DelList(LinkList& L, ElemType x) {
    LNode* p = L->next; // p指向第一个节点
    LNode* pre = L;     // pre指向p的前一个节点
    while (p != NULL) {
        if (p->data == x) {
            pre->next = p->next; // 前一个节点的next指针指向p的下一个节点
            free(p);             // 释放要删除的节点的内存空间
            p = pre->next; // p指向下一个节点
        } else {
            pre = p;     // pre指针向后移动
            p = p->next; // p指针向后移动
        }
    }
    return true; // 删除完成
}

int main(void) {
    int num, data = 0;
    LinkList L;
    InitList(L); // 初始化链表（带头结点）
    printf("请输入存储数量：\n");
    scanf("%d", &num);
    printf("请依次输入数据：\n");
    for (int i = 1; i <= num; i++) {
        scanf("%d", &data);
        InsertList(L, i, data); // 插入到第i个位置的后面
    }
    int denum = 0;
    printf("请输入要删除的数：\n");
    scanf("%d", &denum);
    DelList(L, denum); // 删除值为denum的节点

    printf("链表中的元素：\n");
    LNode* p = L->next; // p指向第一个节点
    while (p != NULL) {
        printf("%d ", p->data); // 输出链表中的元素
        p = p->next;            // 指针p向后移动
    }
    printf("\n");

    return 0;
}