#include <cstddef>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; // 定义数据元素类型为 int

typedef struct LNode {
    ElemType data;      // 数据元素
    struct LNode* next; // 指向下一个节点的指针
} LNode, *LinkList;
/*
  InitList1(LinkList&
L)：带头结点的链表初始化函数。该函数分配内存空间，并将头节点的指针指向该空间。
头节点的 next 域被初始化为空，表示链表为空。
*/
bool InitList1(LinkList& L) {
    L = (LinkList)malloc(sizeof(LNode)); // 分配内存空间，将头节点指针指向该空间
    if (!(L)) {                          // 检查内存分配是否成功
        return false;                    // 分配失败，返回 false
    }
    (L)->next = NULL; // 初始化头节点指针的 next 域为空
    return true;      // 初始化成功，返回 true
}
/*
  InitList(LinkList&
  L)：不带头结点的链表初始化函数。该函数将头节点的指针初始化为空，表示链表为空。
*/
bool InitList(LinkList& L) { // 不带头结点的链表初始化
    L = NULL;                // 初始化头节点指针为空
    return true;             // 初始化成功，返回 true
}
/*
   ListInsert1(LinkList& L, int i, ElemType
e)：带头结点的链表插入函数。该函数在链表的第 i 个位置 插入一个值为 e
的节点。首先检查 i 的合法性，然后遍历链表找到第 i - 1 个位置的节点
p。新建一个节点 s，将其 data 域赋 值为 e，将其 next 域指向 p 的后继节点
p->next，再将 p 的 next 域指向 s，完成插入操作。
*/
bool ListInsert1(LinkList& L, int i, ElemType e) { // 带头结点的链表插入操作
    if (i < 1) { // 如果插入位置小于 1，插入失败
        return false;
    }
    LNode* p;
    int j = 0;
    p = L; // p指向头节点
    while (
        p != NULL &&
        j < i - 1) { // 查找插入位置的前一个节点，不为空且小于i-1时继续指向下一个节点
        p = p->next;
        j++;
    }
    if (p == NULL) { // 如果插入位置超出链表范围，插入失败
        return false;
    }
    LNode* s = (LNode*)malloc(sizeof(LNode)); // 创建新节点
    s->data = e;                              // 赋值
    s->next = p->next; // s放在p后面，将原本p背后那个数接到s后面
    p->next = s;       // 即p的下一个是s
    return true;
}
/*
   ListInsert(LinkList& L, int i, ElemType
e)：不带头结点的链表插入函数。该函数在链表的第 i 个位置插入一个值 为 e
的节点。首先检查 i 的合法性，然后遍历链表找到第 i - 1 个位置的节点
p。如果要在第一个位置插入节点，新建一个 节点 s，将其 data 域赋值为 e，将其 next
域指向原来的第一个节点 L，再将头指针 L 指向 s，完成插入操作。如果不是
在第一个位置插入节点，新建一个节点 s，将其 data 域赋值为 e，将其 next 域指向 p
的后继节点 p->next，再将 p 的 next 域指向 s，完成插入操作。
*/
bool ListInsert(LinkList& L, int i, ElemType e) { // 不带头结点的链表插入操作
    if (i < 1) { // 如果插入位置小于 1，插入失败
        return false;
    }
    LNode* p;
    int j = 1;
    p = L;                           // p指向头节点
    while (p != NULL && j < i - 1) { // 查找插入位置的前一个节点
        p = p->next;
        j++;
    }
    if (j == 1) { // 如果要在第一个位置插入节点
        LNode* s = (LNode*)malloc(sizeof(LNode)); // 创建新节点
        s->data = e;                              // 赋值
        s->next = L; // s放在第一个位置，将原本第一个节点接到s后面
        L = s;       // 头指针指向新节点
        return true;
    } else if (p == NULL) { // 如果插入位置超出链表范围，插入失败
        return false;
    }
    LNode* s = (LNode*)malloc(sizeof(LNode)); // 创建新节点
    s->data = e;                              // 赋值
    s->next = p->next; // s放在p后面，将原本p背后那个数接到s后面
    p->next = s;       // 即p的下一个是s
    return true;
}
/*
   del_x1(LinkList& L, ElemType
x)：带头结点的链表删除节点函数。该函数遍历链表，找到值为 x 的节点并删除。
如果当前节点的值为
x，删除该节点并递归调用函数，继续删除下一个节点；如果当前节点的值不为
x，继续向下遍历。这样写的目的是为了在删除节点时保持链表的正确连接，并且删除所有符合条件的节点。
直接遍历链表进行删除操作可能会导致链表连接的破坏或漏删节点的情况。
*/
void del_x1(LinkList& L, ElemType x) { // 带头结点的链表删除节点
    if (L == NULL) {                   // 如果链表为空，直接返回
        return ;
    }
    if (L->data == x) { // 如果当前节点的值为x，删除该节点
        LinkList p = L;
        L = L->next;
        free(p);
        del_x1(L, x); // 递归删除下一个节点
    } else {          // 如果当前节点的值不为x，继续向下遍历
        LinkList p = L;
        while (p->next != NULL && p->next->data != x) { // 查找值为x的节点
            p = p->next;
        }
        if (p->next != NULL) { // 如果找到值为x的节点，删除该节点
            LinkList q = p->next;
            p->next = q->next;
            free(q);
            del_x1(L, x); // 递归删除下一个节点
        } else {
            del_x1(L->next, x); // 如果没有找到值为x的节点，继续向下遍历
        }
    }
}
/*
del_x(LinkList& L, ElemType
x)：不带头结点的链表删除节点函数。该函数遍历链表，找到值为 x 的节点并删除。
如果当前节点的值为
x，删除该节点并递归调用函数，继续删除下一个节点；如果当前节点的值不为
x，继续遍历下一个 节点，继续判断是否为值为 x 的节点，直到链表末尾。
*/
void del_x(LinkList& L, ElemType x) { // 不带头结点的链表删除节点
    if (L == NULL) {                  // 如果链表为空，直接返回
        return;
    }
    if (L->data == x) { // 如果当前节点的值为 x，删除该节点
        LinkList p = L; // 保存当前节点的指针到 p
        L = L->next; // 将链表的头指针指向下一个节点，跳过当前节点
        free(p);     // 释放 p 所指向的内存空间，即删除节点 p
        del_x(L, x); // 递归删除下一个节点
    } else {         // 如果当前节点的值不为 x，继续向下遍历
        del_x(L->next, x); // 递归删除下一个节点
    }
}

int main(void) {
    int num, data = 0;
    LinkList L;
    InitList(L); // 初始化不带头结点的链表
    printf("请输入存储数量：\n");
    scanf("%d", &num);
    printf("请依次输入数据：\n");
    for (int i = 1; i <= num; i++) {
        scanf("%d", &data);
        ListInsert(L, i, data); // 插入到第i个位置的后面
    }
    int denum = 0;
    printf("请输入要删除的数：\n");
    scanf("%d", &denum);
    del_x1(L, denum); // 删除值为3的节点，使用带头结点的链表删除函数

    while (L != NULL) { // 输出链表中的元素
        printf("%d ", L->data);
        L = L->next;
    }
    return 0;
}