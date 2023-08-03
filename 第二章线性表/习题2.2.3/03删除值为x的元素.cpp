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
// 循环中通过记录在范围内的元素个数 k，然后将不在该范围内的元素向前移动，最后将顺序表的长度减去 k
// 就可以实现删除在范围内的元素。
// 具体来说，当循环结束后，k 的值就是在范围内的元素个数。因为在循环中，每当一个符合条件的元素被找到
// （即 L.data[i] 的值在规定范围内），k 的值就会加一。而当一个不符合条件的元素被找到时，它会被移动到
// 前面符合条件的元素的的位置上，也就是 L.data[i-k] 的位置上。这样，经过一次循环后，在范围内的元素不变
// 而不在该范围内的元素就会被保留在原位，且它们的位置索引会减去 k（即前移k位）。
// 最后，将顺序表的长度减去 k，就可以删除在范围内的元素，即删除表尾的元素。因为 k 记录的是在范围内的元素个数
// 所以将顺序表的长度减去 k，就相当于将这些元素从顺序表中删除。
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
    DeListX2(L, 5); // 删除值为 5 的元素
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]); // 输出删除后的顺序表元素
    }
    return 0;
}