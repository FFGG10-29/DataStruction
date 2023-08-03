#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define InitSize 20
typedef int ElemType;
typedef struct {
    ElemType* data;
    int length;
    int MaxSize;
} SqList;
bool InitList(SqList& L) {
    L.data = (ElemType*)malloc(InitSize * sizeof(ElemType));
    L.length = 0;
    L.MaxSize = InitSize;
    return true;
}
bool CombineList(SqList& L1, SqList& L2, SqList& C) {
    if (L1.length < 0 || L2.length < 0) {
        return false;
    }
    C.length = L1.length + L2.length;
    for (int i = 0; i < C.length; i++) {
        if (i < L1.length) {
            C.data[i] = L1.data[i];
        } else {
            C.data[i] = L2.data[i - L1.length];
        }
    }
    return true;
}
/*
  在修改后的代码中，外层循环控制冒泡的趟数，内层循环则用来比较相邻的元素并交换它们的位置。每进行一趟冒泡
就能将当前序列中的最大元素移动到最后一个位置，因此在下一趟冒泡时就可以不再考虑最后一个元素。当所有的趟数都完成后，整个序列就会被排序好。
  需要注意的是，如果序列中存在相同的元素，那么排序算法可能会改变它们的相对顺序。如果需要保留相同元素的相对顺序
可以使用稳定的排序算法，例如归并排序和插入排序
  在这段代码中，外层循环变量 `i` 表示冒泡的趟数，内层循环变量 `j` 则表示当前趟数下需要比较的元素的下标。
因为每进行一趟冒泡都能将当前序列中的一个最大元素移动到末尾，所以在外层循环中只需要进行 `L.length - 1` 次冒泡就可以将整个序列排好序，
因为最后剩下来的一个数不用排序了，直接就是最小的且在第一位。
  内层循环中，变量 `j` 的取值范围是从 `0` 到 `L.length - i - 2`，这是因为每进行一趟冒泡
都能将当前序列中的一个最大元素移动到末尾，所以在下一趟冒泡时就可以不再考虑已经排好序的末尾部分。
因此，内层循环中只需要比较前 `L.length - i - 1` 个元素即可。
  如果你想使用 `if (L.data[j-1] > L.data[j ])` 进行比较，可以将内层循环的取值范围修改为 `1` 到 `L.length - i - 1`，然后将比较语句修改为：
           if (j > 0 && L.data[j-1] > L.data[j]) {
               temp = L.data[j-1];
               L.data[j-1] = L.data[j];
               L.data[j] = temp;
            }
  这样就可以比较相邻的两个元素并交换它们的位置了。需要注意的是，在比较元素之前需要先判断 `j` 是否大于 `0`，以防止数组越界。
*/
bool SortingListData(SqList& L) {
    int temp = 0;
    for (int i = 0; i < L.length - 1; i++) {
        for (int j = 0; j < L.length - i - 1; j++) {
            if (L.data[j] > L.data[j + 1]) {
                temp = L.data[j];
                L.data[j] = L.data[j + 1];
                L.data[j + 1] = temp;
            }
        }
    }
    return true;
}
/*
bool SortingListData(SqList& L) {
    int temp = 0;
    for (int i = 0; i < L.length; i++) {
        if (i >= 1 && L.data[i] < L.data[i - 1]) {
            temp = L.data[i - 1];
            L.data[i - 1] = L.data[i];
            L.data[i] = temp;
        }
    }
    return true;
}
  在代码中，使用的是一种类似于冒泡排序的算法，但是存在一些逻辑问题。具体来说，当前的排序算法只进行了一趟冒泡
它只比较了相邻的两个元素，如果它们的顺序不正确，就将它们交换位置。但是，这种算法只能保证每次冒泡结束后最后一个元素是正确的
而不能保证整个序列都是排好序的。因此，需要对算法进行修改，使其能够进行多趟冒泡，直到整个序列都排好序为止。
*/
int main(void) {
    SqList L1, L2, C;
    InitList(L1);
    InitList(L2);
    InitList(C);
    printf("请输入L1的数据并回车：\n");
    for (int i = 0; i < 4; i++) {
        scanf("%d", &L1.data[i]);
        L1.length++;
    }
    printf("请输入L2的数据并回车：\n");
    for (int j = 0; j < 3; j++) {
        scanf("%d", &L2.data[j]);
        L2.length++;
    }
    CombineList(L1, L2, C);
    printf("以下是两个顺序表结合的结果：\n");
    for (int k = 0; k < C.length; k++) {
        printf("%d", C.data[k]);
    }
    printf("\n");
    SortingListData(C);
    printf("以下是两个顺序表结合并从小到大排序的结果：\n");
    for (int k = 0; k < C.length; k++) {
        printf("%d", C.data[k]);
    }
    return 0;
}