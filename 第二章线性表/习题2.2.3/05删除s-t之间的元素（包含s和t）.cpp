#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define InitSize 100 // 定义顺序表的最大长度为 100

typedef int ElemType; // 定义顺序表中元素的类型为 int

typedef struct { // 定义顺序表结构体
    ElemType data[InitSize]; // 存储元素的数组
    int length; // 当前长度
    int MaxSize; // 最大长度
} SqList;

bool InitList(SqList& L) { // 初始化顺序表
    L.length = 0; // 将当前长度设置为 0
    L.MaxSize = InitSize; // 将最大长度设置为 InitSize
    return true; // 返回初始化成功
}
/*
  定义了一个名为 DeleteSAndT 的函数，用来删除顺序表中在 [s,t] 范围内的元素。该函数接受一个 
SqList 类型的引用 L，以及两个整型参数 s 和 t，以及一个 ElemType 类型的参数 e。函数返回一个布尔值。
  函数中定义了一个整型变量 k，用来记录在 [s,t] 范围内的元素个数。如果 t 小于 s，或者顺序表 L 的长度
小于 0 或者大于最大长度 MaxSize，则返回 false。
  在循环中，如果当前元素 L.data[i] 的值在 [s,t] 范围内，则将 k 的值加一；
否则，将当前元素 L.data[i] 移动到前面的位置上，即 L.data[i-k] = L.data[i]。
  循环结束后，将顺序表的长度减去 k，即可删除在 [s,t] 范围内的元素。因为 k 记录的是在 [s,t] 范围内
的元素个数，所以将顺序表的长度减去 k，就相当于将这些元素从顺序表中删除。
最后，函数返回 true，表示删除操作成功。*/
bool DeleteSAndT(SqList& L, int s, int t, ElemType e) { // 删除顺序表中在 [s,t] 范围内的元素
    int k = 0; // 记录在 [s,t] 范围内的元素个数
    if (t < s || L.length < 0 || L.length > L.MaxSize) { // 如果 t 小于 s，或者顺序表 L 的长度小于 0 或者大于最大长度 MaxSize，则返回删除失败
        return false;
    }
    for (int i = 0; i < L.length; i++) { // 遍历顺序表中的元素
        if (L.data[i] >= s && L.data[i] <= t) { // 如果当前元素的值在 [s,t] 范围内，则将 k 的值加一
            k++;
        } else { // 如果当前元素的值不在 [s,t] 范围内，则将当前元素移动到前面的位置上
            L.data[i - k] = L.data[i];
        }
    }
    L.length -= k; // 将顺序表的长度减去 k，即可删除在 [s,t] 范围内的元素
    return true; // 返回删除成功
}

int main(void) {
    int num = 0; // 定义一个整型变量 num
    SqList L; // 定义一个 SqList 类型的变量 L
    InitList(L); // 初始化 L
    L.data[0] = 1; // 给 L 中的元素赋值
    L.data[1] = 2;
    L.data[2] = 3;
    L.data[3] = 4;
    L.data[4] = 5;
    L.data[5] = 6;
    L.data[6] = 7;
    L.data[7] = 8;
    L.data[8] = 9;
    L.data[9] = 10;
    L.data[10] = 11;
    L.data[11] = 12;
    L.length = 12; // 将 L 的长度设置为 12
    if (DeleteSAndT(L, 2, 8, num)) { // 删除在 [2,8] 范围内的元素
        printf("删除成功"); // 如果删除成功，打印提示信息
    } else {
        printf("删除失败"); // 如果删除失败，打印提示信息
    }
    for (int i = 0; i < L.length; i++) { // 遍历顺序表中的元素，并打印出来
        printf("%d", L.data[i]);
    }
    return 0; // 返回程序执行成功
}