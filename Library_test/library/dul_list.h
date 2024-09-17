#include <iostream>
#include <malloc.h>
using namespace std;

typedef int Elemtype;

typedef struct Dulnode
{
    Elemtype data;
    Dulnode *prior;
    Dulnode *next;
} Dulnode, *Dullinklist;

// 获取双向链表长度
int List_length(Dullinklist &L)
{
    // 判断链表是否存在
    if (!L)
    {
        cout << "list no found" << endl;
        return -1;
    }
    int count = 0;
    Dullinklist p = L;
    while (p)
    {
        p = p->next;
        count++;
    }
    return count;
}

// 判空
bool Empty(Dullinklist &L)
{
    return (L == NULL);
}

// 初始化双向链表
void Init_list(Dullinklist &L, Elemtype e)
{
    Dullinklist newbase = (Dullinklist)malloc(sizeof(Dulnode));
    if (!newbase)
    {
        cout << "malloc error" << endl;
        return;
    }
    newbase->data = e;
    newbase->next = NULL;
    newbase->prior = NULL;
    L = newbase;
    return;
}

// 头插法
void Insert_head(Dullinklist &L, Elemtype e)
{
    // 判断链表是否存在
    if (Empty(L))
    {
        cout << "list not found" << endl;
        return;
    }
    Dullinklist new_node = (Dullinklist)malloc(sizeof(Dulnode));
    if (!new_node)
    {
        cout << "malloc error" << endl;
        return;
    }
    new_node->data = e;
    new_node->prior = NULL;
    new_node->next = L;
    L->prior = new_node;
    // 更新头节点位置
    L = new_node;
    return;
}

// 尾插法
void Insert_last(Dullinklist &L, Elemtype e)
{
    // 判断链表是否存在
    if (Empty(L))
    {
        cout << "list not found" << endl;
        return;
    }
    Dullinklist new_node = (Dullinklist)malloc(sizeof(Dulnode));
    if (!new_node)
    {
        cout << "malloc error" << endl;
        return;
    }
    new_node->data = e;
    new_node->next = NULL;
    Dullinklist p = L;
    while (p->next)
    {
        p = p->next;
    }
    p->next = new_node;
    new_node->prior = p;
    return;
}

// 在位置i前插入元素
void Insert_elem(Dullinklist &L, int i, Elemtype e)
{
    // 判断链表是否存在
    if (Empty(L))
    {
        cout << "list not found" << endl;
        return;
    }
    int n = List_length(L);
    // 判断位置是否合法
    if (i <= 0 || i > n + 1)
    {
        cout << "position error" << endl;
        return;
    }
    if (i == 1)
    {
        Insert_head(L, e);
        return;
    }
    if (i == n + 1)
    {
        Insert_last(L, e);
        return;
    }
    Dullinklist new_node = (Dullinklist)malloc(sizeof(Dulnode));
    if (!new_node)
    {
        cout << "malloc error" << endl;
        return;
    }
    new_node->data = e;
    Dullinklist p1 = L, p2 = L;
    i--;
    while (i)
    {
        p2 = p1;
        p1 = p1->next;
        i--;
    }
    new_node->prior = p2;
    new_node->next = p1;
    p2->next = new_node;
    p1->prior = new_node;
}

// 删除位置i的元素
void Delete_elem(Dullinklist &L, int i)
{
    // 判断链表是否存在
    if (Empty(L))
    {
        cout << "list not found" << endl;
        return;
    }
    int n = List_length(L);
    // 判断位置是否合法
    if (i <= 0 || i > n)
    {
        cout << "position error" << endl;
        return;
    }
    Dullinklist p1 = L, p2 = NULL;
    if (i == 1)
    {
        L = L->next;
        L->prior = NULL;
        p1->next = NULL;
        free(p1);
        return;
    }
    else if (i == n)
    {
        while (p1->next)
        {
            p2 = p1;
            p1 = p1->next;
        }
        p2->next = NULL;
        p1->prior = NULL;
        free(p1);
        return;
    }
    i--;
    while (i)
    {
        p2 = p1;
        p1 = p1->next;
        i--;
    }
    p1->next->prior = p2;
    p2->next = p1->next;
    p1->next = NULL;
    p1->prior = NULL;
    free(p1);
    return;
}

// 寻找某元素第一次出现的位置，若链表不存在或元素不存在则返回-1
int Find_elem(Dullinklist &L, Elemtype e)
{
    // 判断链表是否存在
    if (Empty(L))
    {
        cout << "list not found" << endl;
        return -1;
    }
    Dullinklist p = L;
    int pos = 1;
    while (p)
    {
        if (p->data == e)
        {
            return pos;
        }
        p = p->next;
        pos++;
    }
    return -1;
}

// 销毁链表
void Destroy_list(Dullinklist &L)
{
    // 判断链表是否存在
    if (Empty(L))
    {
        cout << "list not found" << endl;
        return;
    }
    Dullinklist p = L, temp = L;
    while (p->next)
    {
        temp = p;
        p = p->next;
        p->prior = NULL;
        temp->prior = NULL;
        temp->next = NULL;
        free(temp);
    }
    temp = p;
    temp->prior = NULL;
    temp->next = NULL;
    free(temp);
    L = NULL;
    return;
}

// 打印双向链表
void Print_list(Dullinklist &L)
{
    // 判断链表是否存在
    if (Empty(L))
    {
        cout << "list no found" << endl;
        return;
    }
    Dullinklist p = L;
    while (p)
    {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
    return;
}
