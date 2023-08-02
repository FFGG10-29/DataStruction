#include <cstddef>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define InitSize 10
typedef int ElemType;
typedef struct {
    ElemType data[InitSize];
    int length;
    int MaxSize;
} SqList;
//初始化顺序表
bool InitList(SqList& L) {
    L.length = 0;
    L.MaxSize = InitSize;
    return true;
}

// 从顺序表中删除值为 x 的元素
bool DeListX(SqList& L, ElemType x) {
    int k = 0; // 记录值为 x 的元素个数
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == x) {
            k++; // 找到一个值为 x 的元素
        } else {
            L.data[i - k] = L.data[i]; // 将元素前移 k 个位置
        }
    }
    L.length -= k; // 修改顺序表的长度
    return true;
}
//快慢指针，更加高效
bool DeListX2(SqList& L, ElemType x) {
    int slow = 0;
    for (int fast = 0; fast < L.length; fast++) {
        if (L.data[fast] != x) {
            L.data[slow] = L.data[fast];
            slow++;
        }
    }
    L.length = slow;
    return true;
}

int main(void) {
    SqList L;
    InitList(L); // 初始化顺序表
    L.data[0] = 1;
    L.data[1] = 5;
    L.data[2] = 2;
    L.data[3] = 5;
    L.data[4] = 3;
    L.length = 5;  // 设置顺序表的长度
    DeListX(L, 5); // 删除值为 5 的元素
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]); // 输出删除后的顺序表元素
    }
    return 0;
}