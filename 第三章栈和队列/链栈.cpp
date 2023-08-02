#include <iostream>
#include <stdbool.h>
using namespace std;

// 定义栈的最大长度为 100
#define MaxSize 100
// 栈元素类型定义为 int
typedef int ElemType;
// 状态类型定义为 bool
typedef bool Status;

// 定义栈的链式存储结构
typedef struct StackNode {
    ElemType data;
    struct StackNode* next;
} StackNode, *LinkStack;

// 初始化栈
Status InitStack(LinkStack& S) {
    S = NULL;
    return true;
}

// 入栈操作
Status Push(LinkStack& S, ElemType e) {
    StackNode* p = new StackNode(); // 创建新结点
    p->data = e;                    // 赋值
    p->next = S;                    // 新结点指针指向原栈顶结点
    S = p;                          // 栈顶指针指向新结点
    return true;
}

// 出栈操作
Status Pop(LinkStack& S, ElemType& e) {
    if (S == NULL) {
        // 栈为空，无法出栈
        return false;
    }
    StackNode* p = S; // 指向栈顶结点
    e = S->data;      // 取出栈顶元素
    S = S->next;      // 栈顶指针指向下一个结点
    delete p;         // 释放栈顶结点的内存空间
    return true;
}

// 获取栈顶元素
ElemType GetTop(LinkStack& S, ElemType& e) {
    if (S != NULL) {
        // 栈非空，返回栈顶元素
        e = S->data;
        return e;
    }
    // 栈为空，返回 0
    return 0;
}

// 主函数
int main(void) {
    LinkStack L;
    if (InitStack(L)) {
        cout << "栈初始化成功。" << endl;
    } else {
        cout << "栈初始化失败。" << endl;
    }
    return 0;
}