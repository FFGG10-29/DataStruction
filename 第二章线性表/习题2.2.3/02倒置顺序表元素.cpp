#include <stdio.h>

#define MaxSize 50 // 定义顺序表的最大长度为 50
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize]; // 定义一个固定大小的整型数组，用于存储顺序表中的元素
    int length; // 顺序表的当前长度
} SqList;
// void Reverse(SqList* L) {
//     ElemType temp;
//     for (int i = 0; i < L->length / 2; i++) {
//         temp = L->data[i];
//         L->data[i] = L->data[L->length - i - 1];
//         L->data[L->length - i - 1] = temp;
//     }
// }上面这个Reverse 函数的参数类型是 SqList*，即指向 SqList
// 结构体类型的指针。而在这段代码中，Reverse 函数的参数类型是 SqList&，即对
// SqList 结构体类型的引用
// 将顺序表中的元素倒置
void Reverse(SqList& L) {
    ElemType temp;
    for (int i = 0; i < L.length / 2; i++) {
        temp = L.data[i];
        L.data[i] = L.data[L.length - i - 1]; // 将第 i 个元素和第 length-i-1 个元素交换
        L.data[L.length - i - 1] = temp;
    }
}
int main(void) {
    SqList L = {1, 2, 3, 4, 5, 6}; // 创建一个长度为 6 的顺序表，并初始化元素
    L.length = 6; // 设置顺序表的当前长度为 6
    // Reverse(&L);在之前的代码中，我们调用 Reverse 函数时使用的是结构体类型变量
    // L 的地址，即 &L。而在这段代码中，我们直接使用结构体类型变量 L
    // 作为参数。这是因为在使用引用作为函数参数时，可以直接传递变量本身，而不需要使用取地址符
    // &。
    Reverse(L); // 将顺序表中的元素倒置
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]); // 输出倒置后的顺序表中的元素
    }
    return 0;
}