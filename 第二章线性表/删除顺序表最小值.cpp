#include <stdbool.h>
#include <stdio.h>

#define MaxSize 100 // 定义顺序表的最大长度为 100
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize]; // 定义一个固定大小的整型数组，用于存储顺序表中的元素
    int length; // 顺序表的当前长度
} SqList;

// 删除顺序表中的最小值
bool Del_Min(SqList& L, ElemType& value) {
    if (L.length == 0) // 如果顺序表为空，则删除失败
        return false;
    value = L.data[0];                 // 假设第一个元素为最小值
    int pos = 0;                       // 最小值的下标
    for (int i = 0; i < L.length; i++) // 遍历整个顺序表，找到最小值及其下标
        if (L.data[i] < value) {
            value = L.data[i];
            pos = i;
        }
    L.data[pos] = L.data[L.length - 1]; // 将最小值与最后一个元素交换
    L.length--;                         // 删除最小值
    return true;                        // 删除成功，返回 true
}

int main(void) {
    int length = 6;                // 定义顺序表的初始长度为 6
    SqList L = {1, 2, 3, 4, 5, 6}; // 创建一个长度为 6 的顺序表，并初始化元素
    ElemType value; // 定义一个变量，用于保存被删除的最小值
    if (Del_Min(L, value)) // 删除顺序表中的最小值
        printf("The minimum value %d has been deleted.\n",
               value); // 输出被删除的最小值
    else
        printf("The list is empty.\n"); // 如果顺序表为空，则输出提示信息
    return 0;
}