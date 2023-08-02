#include <stdio.h>
#include <stdlib.h>

#define InitSize 10
typedef int ElemType;
typedef struct {
    ElemType data[InitSize]; // 静态分配数组空间
    int length;              // 当前长度
    int MaxSize;             // 最大长度
} Sqlist;

// 初始化顺序表
void InitList(Sqlist& L) {
    L.length = 0;         // 将当前长度初始化为 0
    L.MaxSize = InitSize; // 将最大长度初始化为 MaxSize
}

// 在顺序表中插入元素
void ListInsert(Sqlist& L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1) { // 插入位置不合法
        printf("插入位置不合法！\n");
        return;
    }
    if (L.length == L.MaxSize) { // 顺序表已满，无法插入
        printf("顺序表已满，无法插入！\n");
        return;
    }
    for (int j = L.length; j >= i;
         j--) { // 将插入位置之后的元素依次向后移动一位
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e; // 将需要插入的元素插入到指定位置
    L.length++;        // 将顺序表的当前长度加 1
}

void ListDelete(Sqlist& L, int i, int& value) {
    if (i < 1 || i > L.length) { // 删除位置不合法
        printf("删除位置不合法！\n");
        return;
    }
    value = L.data[i - 1]; // 获取删除的元素值
    for (int j = i; j < L.length; j++) { // 将删除位置之后的元素依次向前移动一位
        L.data[j] = L.data[j + 1];
    }
    L.length--; // 将顺序表的当前长度减 1
}

ElemType GetElem(Sqlist L, int i) { return L.data[i - 1]; }
int main(void) {
    Sqlist L;
    InitList(L);                   // 初始化顺序表
    for (int i = 1; i <= 5; i++) { // 使用 ListInsert 函数插入前 5 个元素
        ListInsert(L, i, i);
    }
    ListInsert(L, 6, 99);                // 在第 6 个位置插入元素 99
    for (int i = 0; i < L.length; i++) { // 输出顺序表中的所有元素
        printf("%d ", L.data[i]);
    }
    printf("\n");
    int value;
    ListDelete(L, 1, value); // 删除第 3 个位置的元素，并获取其值
    printf("删除的元素值为：%d\n", value);
    for (int i = 0; i < L.length; i++) { // 再次输出顺序表中的所有元素
        printf("%d ", L.data[i]);
    }
    int n = GetElem(L, 2);
    printf("chazhaochenggong: %d\n", n);
    printf("\n");
    return 0;
}