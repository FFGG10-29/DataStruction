#include <iostream>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define InitSize 100
typedef int ElemType;
typedef struct {
    ElemType data[InitSize];
    int length;
    int MaxSize;
} SqList;
/*应该将符合条件的元素删除，同时将顺序表的长度减一。
另外，由于删除元素会改变顺序表的长度，因此在循环中应该使用动态下标 i-k 进行元素的移动
函数将符合删除条件的元素移动到了前面的位置上，而第二个自己写的函数则是将后面的元素向前移动
覆盖掉符合删除条件的元素。因此，第一个函数的实现方式保持了顺序表中元素的顺序

循环中通过记录在 [s,t] 范围内的元素个数 k，然后将不在该范围内的元素向前移动，最后将顺序表的长度减去 k
就可以实现删除在 [s,t] 范围内的元素。
具体来说，当循环结束后，k 的值就是在 [s,t] 范围内的元素个数。因为在循环中，每当一个符合条件的元素被找到
（即 L.data[i] 的值在 (s,t) 范围内），k 的值就会加一。而当一个不符合条件的元素被找到时，它会被移动到
前面符合条件的元素的的位置上，也就是 L.data[i-k] 的位置上。这样，经过一次循环后，在 （s,t） 范围内的元素不变
而不在该范围内的元素就会被保留在原位，且它们的位置索引会减去 k（即前移k位）。
最后，将顺序表的长度减去 k，就可以删除在 [s,t] 范围内的元素，即删除表尾的元素。因为 k 记录的是在 [s,t] 范围内的元素个数
所以将顺序表的长度减去 k，就相当于将这些元素从顺序表中删除。*/
bool DeleteSToT(SqList& L, int s, int t, ElemType& e) {
    int k = 0;
    if (s > t || L.length < 0 || L.length > L.MaxSize) {
        return false;
    }
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] > s && L.data[i] < t) {
            k++;
        } else {
            L.data[i - k] = L.data[i];
        }
    }
    L.length -= k;
    return true;
}
/*
bool DeleteSToT(SqList& L, int s, int t, ElemType& e) {
    if (s > t || L.length < 0 || L.length > L.MaxSize) {
        return false;
    }
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] > s && L.data[i] < t) {
            L.data[i - 1] = L.data[i];
            L.length--;
        }
    }
    return true;
}

在 DeleteSToT函数中，使用后面的元素覆盖前面的元素的确可以达到类似删除的效果，但是这种方式也会导致一些问题。
假设要删除的范围为 [s,t]，当前的循环变量为 i，如果 L.data[i]
符合删除条件，那么将会执行 L.data[i-1] = L.data[i] 这一语句，将 L.data[i]
的值赋给 L.data[i-1]，这样会将 i-1 位置的元素覆盖。但是，由于当前的循环变量是
i，而在下一次循环时，又会将 i+1 位置的元素复制到 i
位置上，这样就相当于把原本要删除的元素移动到了 i-2 的位置上，而并没有真正删除。
此外，使用后面的元素覆盖前面的元素会导致顺序表中的元素顺序发生改变，可能会给后续的操作带来麻烦。
因此，一般来说，删除元素应该采用将后面的元素向前移动的方式，并将顺序表的长度减一，这样才能真正地删除目标元素，并保持顺序表的有序性。
*/

int main(void) {
    int num = 0;
    SqList L;
    L.data[0] = 1;
    L.data[1] = 3;
    L.data[2] = 4;
    L.data[3] = 2;
    L.data[4] = 2;
    L.data[5] = 8;
    L.data[6] = 9;
    L.data[7] = 12;
    L.length = 8;
    if (DeleteSToT(L, 2, 9, num)) {
        printf("删除成功\n");
    } else {
        printf("删除失败\n");
    }
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
    return 0;
}