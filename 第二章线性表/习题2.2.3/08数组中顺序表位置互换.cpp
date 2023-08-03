#include <stdio.h>

#define MAXSIZE 100

typedef struct {
    int data[MAXSIZE];
    int length;
} SqList;

void InitList(SqList* L) { L->length = 0; }

void CreateList(SqList* L, int n) {
    if (n > MAXSIZE) {
        printf("错误：输入的大小超过了最大限制。\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &L->data[i]);
        L->length++;
    }
}

void Exchange(SqList* A, int n, int m) {
    for (int i = 0; i < n; i++) {
        int temp = A->data[i];
        A->data[i] = A->data[i + n];
        A->data[i + n] = temp;
    }
}

void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

int main() {
    SqList A;
    int n, m;
    InitList(&A);
    printf("请输入第一个顺序表的长度：");
    scanf("%d", &n);
    printf("请输入第一个顺序表的元素：");
    CreateList(&A, n);
    printf("第一个顺序表：");
    PrintList(A);
    printf("请输入第二个顺序表的长度：");
    scanf("%d", &m);
    printf("请输入第二个顺序表的元素：");
    InitList(&A);
    CreateList(&A, m);
    printf("第二个顺序表：");
    PrintList(A);
    Exchange(&A, n, m);
    printf("交换后的顺序表：\n");
    PrintList(A);
    return 0;
}