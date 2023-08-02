#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 定义队列的最大长度为 100
#define MAXQSIZE 100
// 队列元素类型定义为 int
typedef int QElemType;

// 定义循环队列的结构体
typedef struct {
    QElemType* data;  // 存储队列元素的数组指针
    int front;        // 指向队头的指针
    int rear;         // 指向队尾的指针
} SqQueue;

// 初始化队列
bool InitQueue(SqQueue& Q) {
    Q.data = new QElemType[MAXQSIZE];  // 为队列分配空间
    if (!Q.data) {
        // 分配空间失败，返回 false
        return false;
    }
    Q.front = Q.rear = 0;  // 初始化队头和队尾指针
    return true;
}

// 求队列长度
int QueueLenth(SqQueue Q) {
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;  // 循环队列求长度
}

// 入队操作
bool EnQueue(SqQueue& Q, QElemType e) {
    if ((Q.rear + 1) % MAXQSIZE == Q.front) {
        // 队列已满，无法入队
        return false;
    }
    Q.data[Q.rear] = e;  // 将元素插入队尾
    Q.rear = (Q.rear + 1) % MAXQSIZE;  // 队尾指针向后移动
    return true;
}

// 出队操作
bool DeQueue(SqQueue& Q, QElemType& e) {
    if (Q.front == Q.rear) {
        // 队列为空，无法出队
        return false;
    }
    e = Q.data[Q.front];  // 取出队头元素
    Q.front = (Q.front + 1) % MAXQSIZE;  // 队头指针向后移动
    return true;
}

// 获取队头元素
bool GetQueue(SqQueue& Q, QElemType& x) {
    if (Q.front == Q.rear) {
        // 队列为空，无法获取队头元素
        return false;
    }
    x = Q.data[Q.front];  // 取出队头元素
    return true;
}

// 主函数
int main(void) {
    SqQueue Q;
    if (InitQueue(Q)) {
        printf("队列初始化成功。\n");
    } else {
        printf("队列初始化失败。\n");
    }

    QElemType e = 1;
    if (EnQueue(Q, e)) {
        printf("元素 %d 入队成功。\n", e);
    } else {
        printf("元素 %d 入队失败。\n", e);
    }

    if (GetQueue(Q, e)) {
        printf("队头元素为 %d。\n", e);
    } else {
        printf("队列为空，无法获取队头元素。\n");
    }

    if (DeQueue(Q, e)) {
        printf("元素 %d 出队成功。\n", e);
    } else {
        printf("队列为空，无法出队。\n");
    }

    printf("队列长度为 %d。\n", QueueLenth(Q));

    return 0;
}