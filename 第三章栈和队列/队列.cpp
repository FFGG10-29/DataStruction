#include <iostream>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 定义队列的最大长度为 100
#define MAXQSIZE 100
// 队列元素类型定义为 int
typedef int QElemType;

// 定义顺序队列的结构体
typedef struct {
    QElemType* base; // 存储队列元素的数组指针
    int front;       // 指向队头的指针
    int rear;        // 指向队尾的指针
} SqQueue;

// 初始化队列
bool InitQueue(SqQueue& Q) {
    Q.base = new QElemType(MAXQSIZE); // 为队列分配空间
    if (!Q.base) {
        // 分配空间失败，返回 false
        return false;
    }
    Q.front = Q.rear = 0; // 初始化队头和队尾指针
    return true;
}

// 入队操作
bool EnQueue(SqQueue& Q, QElemType& x) {
    if (Q.rear + 1 == Q.front) {
        // 队列已满，无法入队
        return false;
    }
    Q.base[Q.rear] = x;  // 将元素插入队尾
    Q.rear = (Q.rear + 1)%10; // 队尾指针向后移动
    // Q.rear = (Q.rear + 1) % MAXQSIZE;  // 循环队列
    return true;
}

// 出队操作
bool DeQueue(SqQueue& Q, QElemType& x) {
    if (Q.rear == Q.front) {
        // 队列为空，无法出队
        return false;
    }
    x = Q.base[Q.front];   // 取出队头元素
    Q.front = Q.front + 1; // 队头指针向后移动
    return true;
}

// 主函数
int main(void) {
    SqQueue Q;
    if (InitQueue(Q)) {
        std::cout << "队列初始化成功。";
    } else {
        std::cout << "队列初始化失败。";
    }
    return 0;
}