#include <cerrno>    // C++ 标准错误码库
#include <cstddef>   // C++ 标准库定义的一些宏和类型（如 NULL）
#include <cstdlib>   // C 标准库函数库
#include <iostream>  // C++ 标准输入输出库
#include <stdbool.h> // C 标准库定义的 bool 类型
#include <stdio.h>   // C 标准输入输出库
#include <stdlib.h>  // C 标准库函数库


// 数据元素类型定义为 int
typedef int ElemType;
// 状态类型定义为 bool
typedef bool Status;

// 双向链表节点类型定义
typedef struct DuLNode {
    ElemType data;         // 数据元素
    struct DuLNode* prior; // 指向前驱节点的指针
    struct DuLNode* next;  // 指向后继节点的指针
} DuLNode, *DuLinkList;

// 初始化双向链表
Status InitList(DuLinkList& L) {
    L = (DuLinkList)malloc(sizeof(DuLNode)); // 分配头节点的内存空间
    if (L == NULL) {
        std::cout << "内存分配失败！" << std::endl;
        return false; // 检查内存分配是否成功
    }
    L->next = NULL;  // 初始化头节点的 next 指针为 NULL
    L->prior = NULL; // 初始化头节点的 prior 指针为 NULL
    return true;
}

// 在节点 p 后插入节点 s
bool InsertNextLnode(DuLNode* p, DuLNode* s) {
    if (s == NULL || p == NULL) {
        std::cout << "插入失败！" << std::endl;
        return false; // 如果 s 或 p 为空，返回插入失败
    }
    s->next = p->next; // s 的 next 指针指向 p 的 next 指针指向的节点
    if (p->next != NULL) {
        p->next->prior =
            s; // 如果 p 的 next 指针指向的节点不为空，将其 prior 指针指向 s
    }
    s->prior = p; // s 的 prior 指针指向 p
    p->next = s;  // p 的 next 指针指向 s
    return true;  // 插入成功，返回 true
}

// 删除节点 q
bool DeleteLnode(DuLNode* p) {
    if (p == NULL) {
        return false;
    }
    DuLNode* q = p->next;
    if (q == NULL || p == NULL || p->next == NULL) {
        std::cout << "删除失败！" << std::endl;
        return false; // 如果 q 或 p 为空，或 p 的 next 指针为空，返回删除失败
    }
    p->next = q->next; // 将 p 的 next 指针指向 q 的下一个节点
    if (q->next != NULL) {
        q->next->prior = p; // 如果 q 的下一个节点不为空，将其 prior 指针指向 p
    }
    free(q);     // 释放 q 节点所占用的内存空间
    return true; // 删除成功，返回 true
}

//销毁双向链表
void DestoryList(DuLinkList& L) {
    while (L->next != NULL) {
        DeleteLnode(L);
    }
    free(L);
    L = NULL;
}

int main(void) {
    DuLinkList L;
    if (InitList(L)) { // 初始化双向链表
        std::cout << "链表初始化成功。"
                  << std::endl; // 输出初始化成功的提示信息
    } else {
        std::cout << "链表初始化失败。"
                  << std::endl; // 输出初始化失败的提示信息
        return -1;
    }

    DuLNode* p = L;                                 // p 指向头节点
    DuLNode* s = (DuLNode*)malloc(sizeof(DuLNode)); // 创建新节点 s
    s->data = 1;                 // 设置新节点的数据元素值
    if (InsertNextLnode(p, s)) { // 在 p 节点后插入新节点 s
        std::cout << "插入成功。" << std::endl;
    } else {
        return -1;
    }

    if (DeleteLnode(p)) { // 删除 q 节点
        std::cout << "删除成功。" << std::endl;
    } else {
        return -1;
    }

    DestoryList(L); // 销毁双向链表

    return 0;
}