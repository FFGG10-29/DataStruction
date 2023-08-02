#include <iostream>
#include <stdbool.h>
using namespace std;

#define MaxSize 100
typedef int ElemType;
typedef bool Status;

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
    StackNode* p = new StackNode();
    p->data = e;
    p->next = S;
    S = p;
    return true;
}

// 出栈操作
Status Pop(LinkStack& S, ElemType& e) {
    if (S == NULL) {
        return false;
    }
    StackNode* p = S;
    e = S->data;
    S = S->next;
    delete p;
    return true;
}

// 获取栈顶元素
ElemType GetTop(LinkStack& S, ElemType& e) {
    if (S != NULL) {
        e = S->data;
        return e;
    }
    return 0;
}

int main(void) {
    LinkStack L;
    if (InitStack(L)) {
        cout << "初始化成功" << endl;
    } else {
        cout << "初始化失败" << endl;
    }
    return 0;
}