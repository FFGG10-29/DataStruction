#include <cstdlib>
#include <stdio.h>
#define InitSize 10 // 定义顺序表的初始大小为 10
typedef struct {
    int* data;   // 指向动态分配的数组的指针
    int MaxSize; // 顺序表的最大长度
    int length;  // 顺序表的当前长度
} Seqlist;

// 初始化顺序表
void Init_List(Seqlist& L) {
    L.data = (int*)malloc(InitSize *
                          sizeof(int)); // 初始化一个大小为 InitSize 的整型数组
    L.length = 0;                       // 将当前长度初始化为 0
    L.MaxSize = InitSize;               // 将最大长度初始化为 InitSize
}

// 增加顺序表的长度
void IncreaseSize(Seqlist& L, int len) {
    int* p = L.data; // 将原有数据的指针保存到临时变量 p 中
    L.data = (int*)malloc((L.MaxSize + len) *
                          sizeof(int)); // 重新分配一个更大的内存空间
    for (int i = 0; i < L.length; i++) {
        L.data[i] = p[i]; // 将原有数据复制到新的内存空间中
    }
    L.MaxSize = L.MaxSize + len; // 更新最大长度的值
    free(p);                     // 释放原有内存空间
}

// 将从键盘输入的数存放到顺序表中
void Input_List(Seqlist& L) {
    printf("请输入顺序表中的元素，输入 -1 结束：\n");
    int x;
    scanf("%d", &x);
    while (x != -1) {
        if (L.length == L.MaxSize) { // 如果顺序表已满，则需要增加顺序表的长度
            IncreaseSize(L, 10); // 增加顺序表的长度
        }
        L.data[L.length] = x; // 将输入的数存放到顺序表中
        L.length++;           // 更新顺序表的长度
        scanf("%d", &x);      // 继续从键盘输入数
    }
}

int main(void) {
    // 程序入口函数
    Seqlist L;
    Init_List(L);
    Input_List(L);
    printf("当前顺序表的长度为：%d\n", L.length);
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    free(L.data); // 释放动态分配的内存
    return 0;
}