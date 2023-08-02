#include <cstdlib>
#include <iostream>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; // 定义数据元素类型为 int
typedef bool Status;  // 定义状态类型为 bool
typedef struct LNode {
    ElemType data;      // 数据元素
    struct LNode* next; // 指向下一个节点的指针
} LNode, *LinkList;     // 定义链表节点类型和链表类型

Status InitList(LinkList& L) {
    L = (LinkList)malloc(sizeof(LNode)); // 分配内存空间，将头节点指针指向该空间
    if (!(L)) {                          // 检查内存分配是否成功
        return false;                    // 分配失败，返回 false
    }
    (L)->next = NULL; // 初始化头节点指针的 next 域为空
    return true;      // 初始化成功，返回 true
}
bool ListInsert(LinkList& L, int i, ElemType e) { //插入操作
    if (i < 1) {
        return false;
    }
    LNode* p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        return false;
    }
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;       //赋值
    s->next = p->next; // s放在p后面，将原本p背后那个数接到s后面
    p->next = s;       //即p的下一个是s
    return true;
}

int main(void) {
    LinkList L;        // 声明一个链表头节点指针
    if (InitList(L)) { // 初始化链表
        printf("List initialized successfully.\n"); // 输出初始化成功的提示信息
    } else {
        printf("Failed to initialize list.\n"); // 输出初始化失败的提示信息
    }
    ListInsert(L, 3, 99);
}