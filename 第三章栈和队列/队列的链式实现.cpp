#include <cerrno> // 引入 C++ 标准错误码库
#include <cstddef> // 引入 C++ 标准库定义的一些宏和类型（如 NULL）
#include <cstdlib>   // 引入 C 标准库函数库
#include <iostream>  // 引入 C++ 标准输入输出库
#include <stdbool.h> // 引入 C 标准库定义的 bool 类型
#include <stdio.h>
#include <stdlib.h>

typedef int QElemType; // 定义队列元素类型为 int

// 定义队列结点的结构体
typedef struct QNode {
    QElemType data;     // 数据域
    struct QNode* next; // 指针域
} QNode, *QueuePtr;

// 定义链式队列的结构体
typedef struct {
    QueuePtr front; // 头指针
    QueuePtr rear;  // 尾指针
} LinkQueue;

// 初始化链式队列
bool InitQNode(LinkQueue& Q) {
    Q.front = Q.rear = new QNode; // 创建头结点
    Q.front->next = NULL;         // 头结点指针域为空
    return true;
}

// 判断队列是否为空
bool IsEmpty(LinkQueue Q) {
    if (Q.front == Q.rear) {
        return true;
    } else {
        return false;
    }
}

// 入队操作
bool EnQueue(LinkQueue& Q, QElemType e) {
    QNode* p = new QNode; // 创建新结点
    p->data = e;          // 将新元素赋值给结点数据域
    p->next = NULL;       // 新结点指针域为空
    Q.rear->next = p;     // 将新结点插入队尾
    Q.rear = p;           // 修改尾指针
    return true;
}

// 出队操作
bool DeQueue(LinkQueue& Q, QElemType& e) {
    if (Q.front == Q.rear) {
        return false;
    }
    QNode* p = Q.front->next; // 指向队头结点
    e = p->data;              // 将队头元素赋值给 e
    Q.front->next = p->next;  // 修改头指针
    if (Q.rear == p) {
        Q.rear = Q.front; // 如果队列中只有一个元素，修改尾指针
    }
    delete p; // 释放队头结点空间
    return true;
}

// 获取队头元素
QElemType GetHead(LinkQueue Q) {
    if (Q.front != Q.rear) 
        return Q.front->next->data;
    
}

// 主函数
int main(void) {
    LinkQueue Q;
    InitQNode(Q);  // 初始化链式队列
    EnQueue(Q, 1); // 入队元素 1
    EnQueue(Q, 2); // 入队元素 2
    QElemType e;
    if (DeQueue(Q, e)) {
        printf("出队元素为 %d\n", e); // 输出出队元素
    }
    printf("队头元素为 %d\n", GetHead(Q)); // 输出队头元素
    return 0;
}