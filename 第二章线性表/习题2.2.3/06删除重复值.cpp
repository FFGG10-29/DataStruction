#include <cstddef>
#include <cstdlib>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define InitSize 10 // 定义顺序表的初始大小为 10

typedef int ElemType;

typedef struct {
    ElemType* data; // 使用指针类型存储元素
    int length;     // 当前顺序表长度
    int MaxSize;    // 最大长度
} SqList;

// 初始化顺序表
bool InitList(SqList& L) {
    L.data =
        (ElemType*)malloc(InitSize * sizeof(ElemType)); // 使用 malloc 分配内存
    L.length = 0;         // 将当前长度初始化为 0
    L.MaxSize = InitSize; // 将最大长度初始化为 InitSize
    return true;
}


/*
  删除顺序表中的重复元素
  这段代码实现了顺序表中删除重复元素的功能。其删除算法的主要思路是：从前往后遍历顺序表，对于每个元素
从它的下一个元素开始往后遍历，找到相同的元素并进行删除，直到遍历到顺序表的末尾。具体的实现细节可以参考代码中的注释。
  下面对该算法的时间复杂度和空间复杂度进行分析：  
  时间复杂度：该算法的时间复杂度为 O(n^2)，其中 n 是顺序表的长度。因为该算法需要对每个元素都进行一次遍历
并且在内部循环中可能需要对一些元素进行删除和移动操作，这些操作都是线性时间复杂度的，所以总的时间复杂度为 O(n^2)。
  空间复杂度：该算法的空间复杂度为 $O(1)$，因为它只需要常数级别的额外空间来保存一些临时变量，而不需要额外开辟新的空间来存储顺序表中的元素。
*/
bool DeleteSame(SqList& L, ElemType& e) {
    int s, k = 0;
    if (L.length < 0) { // 如果顺序表长度小于 0，返回删除失败
        return false;
    }
    for (int i = 0; i < L.length; i++) {
    s = L.data[i];
    k = 0;
    for (int j = i + 1; j < L.length; j++) {
        if (L.data[j] == s) {
            k++;
        } else if (k > 0) {
            L.data[j - k] = L.data[j];
        }
    }
    L.length -= k; // 删除了 k 个元素
    e = L.data[i]; // 将删除的元素赋值给 e
}
    return true;
}

int main(void) {
    int num;
    SqList L;
    InitList(L); // 初始化顺序表
    printf("请输入存入顺序表的数字\n");
    for (int i = 0; i < 8; i++) {
        scanf("%d", &L.data[i]); // 输入顺序表中的元素
        L.length++;
    }
    if (DeleteSame(L, num)) { // 删除重复元素
        printf("删除成功");
    } else {
        printf("删除失败");
    }
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]); // 在每个元素之间添加空格
    }
    printf("\n"); // 输出换行符
    return 0;     // 返回程序执行成功
}