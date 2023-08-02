#include <cerrno>    // C++ 标准错误码库
#include <cstddef>   // C++ 标准库定义的一些宏和类型（如 NULL）
#include <cstdlib>   // C 标准库函数库
#include <iostream>  // C++ 标准输入输出库
#include <stdbool.h> // C 标准库定义的 bool 类型
#include <stdio.h>   // C 标准输入输出库
#include <stdlib.h>  // C 标准库函数库

#define MaxSize 100
// 数据元素类型定义为 int
typedef int SElemType;
// 状态类型定义为 bool
typedef bool Status;
typedef struct {
    SElemType* base;
    SElemType* top;
    int stacksize;
} SqStack;
//初始化
Status InitStack(SqStack& S) {
    S.base = new SElemType(MaxSize);
    if (!S.base) {
        return false;
    }
    S.top = S.base;
    S.stacksize = MaxSize;
    return true;
}
//入栈
Status Push(SqStack& S, SElemType& e) {
    if (S.top - S.base == S.stacksize) {
        return false;
    }
    *S.top++ = e;
    return true;
}
//出栈
Status Pop(SqStack& S, SElemType& e) {
    if (S.top == S.base) {
        return false;
    }
    e = *--S.top;
    return true;
}
//获取顶部数据
int GetTop(SqStack& S, SElemType& e) {
    if (S.top != S.base) {
        return *(S.top - 1);
    }
    return true;
}
int main(void) {
    SqStack s;
    int num = 1;
    if (InitStack(s)) {
        std::cout << "初始化成功。" << std::endl;
    } else {
        std::cout << "初始化失败。" << std::endl;
    }
    for (int i = 0; i <= 10; i++) {
        num *= i;
    }

    if (Push(s, num)) {
        std::cout << "插入成功。" << std::endl;
    } else {
        std::cout << "插入失败。" << std::endl;
    }
    std::cout << GetTop(s, num) << std::endl;
}