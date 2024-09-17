#include <iostream>
#include <cmath>
#include <malloc.h>
using namespace std;

typedef int Elemtype;

typedef struct Node
{
    Elemtype data;
    struct Node *next;
} Node, *List;

// 返回长度
int List_length(List &L)
{
    // 判断链表是否存在
    if (!L)
    {
        cout << "list no found" << endl;
        return -1;
    }
    List p = L->next;
    int length = 0;
    while (p)
    {
        length++;
        p = p->next;
    }
    return length;
}

// 判空
int List_empty(List &L)
{
    // 判断链表是否存在
    if (!L)
    {
        cout << "list no found" << endl;
        return -1;
    }
    return (List_length(L) == 0);
}

// 初始化
void Init_list(List &L)
{
    List newbase = (List)malloc(sizeof(Node));
    if (!newbase)
    {
        cout << "malloc error" << endl;
        return;
    }
    L = newbase;
    // 头指针一般没有数据
    L->data = INT_MIN;
    // 初始化头指针指向
    L->next = NULL;
    return;
}

// 销毁链表
void Destroy_list(List &L)
{
    // 判断链表是否存在
    if (!L)
    {
        cout << "list no found" << endl;
        return;
    }
    List temp = L;
    while (L)
    {
        temp = L;
        L = L->next;
        temp->next = NULL; // 置空
        free(temp);        // 释放
    }
    return;
}

// 置空链表
void Clear_list(List &L)
{
    // 判断链表是否存在
    if (!L)
    {
        cout << "list no found" << endl;
        return;
    }
    L->next = NULL;
    return;
}

// 打印线性表
void Print_list(List &L)
{
    // 判断链表是否存在
    if (!L)
    {
        cout << "list no found" << endl;
        return;
    }

    List p = L->next;
    while (p)
    {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
    return;
}

void Get_elem(List &L, int i, Elemtype &e)
{
    // 判断链表是否存在
    if (!L)
    {
        cout << "list no found" << endl;
        return;
    }
    int n = List_length(L);
    if (i < 1 || i > n)
    {
        cout << "location error" << endl;
        return;
    }
    List p = L;
    while (i)
    {
        p = p->next;
        i--;
    }
    e = p->data;
    return;
}

// 在位置i的前面插入节点
void Insert_elem(List &L, int i, Elemtype e)
{
    // 判断链表是否存在
    if (!L)
    {
        cout << "list no found" << endl;
        return;
    }
    List p = L;
    int n = List_length(L), j = 0;
    if (i < 1 || i > n + 1)
    {
        cout << "location error" << endl;
        return;
    }
    List node = (List)malloc(sizeof(Node));
    if (!node)
    {
        cout << "malloc error" << endl;
        return;
    }
    node->data = e;
    node->next = NULL;
    // 找到插入位置
    while (j < i - 1)
    {
        p = p->next;
        j++;
    }
    node->next = p->next;
    p->next = node;
    return;
}

// 删除第i个元素
void Delete_elem(List &L, int i)
{
    // 判断链表是否存在
    if (!L)
    {
        cout << "list no found" << endl;
        return;
    }
    int n = List_length(L);
    if (i < 1 || i > n)
    {
        cout << "location error" << endl;
        return;
    }
    List pre = NULL, cur = L;
    while (i)
    {
        pre = cur;
        cur = cur->next;
        i--;
    }
    pre->next = cur->next;
    cur->next = NULL; // 置空
    free(cur);        // 释放
    return;
}

// 查找表中是否有某元素
int Find_elem(List &L, Elemtype target)
{
    // 判断链表是否存在
    if (!L)
    {
        cout << "list no found" << endl;
        return -1;
    }
    List p = L->next;
    int location = 1;
    while (p)
    {
        if (target == p->data)
        {
            return location;
        }
        p = p->next;
        location++;
    }
    return -1;
}