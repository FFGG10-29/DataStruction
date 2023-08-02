// 引入 C++ 标准错误码库
#include <cerrno>
// 引入 C++ 标准库定义的一些宏和类型（如 NULL）
#include <cstddef>
// 引入 C 标准库函数库
#include <cstdlib>
// 引入 C++ 标准输入输出库
#include <iostream>
// 引入 C 标准库定义的 bool 类型
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 定义栈的最大长度为 100
#define MaxSize 100
// 数据元素类型定义为 int
typedef int SElemType;
// 状态类型定义为 bool
typedef bool Status;
typedef struct {
    SElemType* base; // 指向栈底的指针
    SElemType* top;  // 指向栈顶的指针
    int stacksize;   // 栈的最大长度
} SqStack;

// 初始化栈
Status InitStack(SqStack& S) {
    // 为栈分配空间
    S.base = new SElemType(MaxSize);
    if (!S.base) {
        return false;
    }
    S.top = S.base;
    S.stacksize = MaxSize;
    return true;
}

// 入栈操作
Status Push(SqStack& S, SElemType& e) {
    if (S.top - S.base == S.stacksize) {
        // 栈满
        return false;
    }
    *S.top++ = e;
    return true;
}

// 出栈操作
Status Pop(SqStack& S, SElemType& e) {
    if (S.top == S.base) {
        // 栈空
        return false;
    }
    e = *--S.top;
    return true;
}

// 获取栈顶元素
int GetTop(SqStack& S, SElemType& e) {
    if (S.top != S.base) {
        // 栈非空
        return *(S.top - 1);
    }
    // 栈空
    return true;
}

int main(void) {
    SqStack s;
    int num = 1;
    if (InitStack(s)) {
        std::cout << "栈初始化成功。" << std::endl;
    } else {
        std::cout << "栈初始化失败。" << std::endl;
    }
    for (int i = 1; i <= 10; i++) {
        num *= i;
    }

    if (Push(s, num)) {
        std::cout << "元素入栈成功。" << std::endl;
    } else {
        std::cout << "元素入栈失败。" << std::endl;
    }

    int top = GetTop(s, num);
    if (top != true) {
        std::cout << "栈顶元素为：" << top << std::endl;
    } else {
        std::cout << "获取栈顶元素失败。" << std::endl;
    }
    return 0;
}