#include <iostream>
#include <malloc.h>
using namespace std;

typedef int Elemtype;

typedef struct Dulnode
{
    Elemtype data;
    Dulnode *prior;
    Dulnode *next;
} Dulnode, *Circle_dullinklist;

// 获取双向循环链表长度
int List_length(Circle_dullinklist &L)
{
    // 判断链表是否存在
    if (!L)
    {
        cout << "list no found" << endl;
        return -1;
    }
    int count = 1;
    Circle_dullinklist p = L;
    p = p->next;
    while (p != L)
    {
        p = p->next;
        count++;
    }
    return count;
}

// 判空
bool Empty(Circle_dullinklist &L)
{
    return (L == NULL);
}

// 初始化双向循环链表
void Init_list(Circle_dullinklist &L, Elemtype e)
{
    Circle_dullinklist newbase = (Circle_dullinklist)malloc(sizeof(Dulnode));
    if (!newbase)
    {
        cout << "malloc error" << endl;
        return;
    }
    newbase->data = e;
    newbase->next = newbase;
    newbase->prior = newbase;
    L = newbase;
    return;
}

// 头插法
void Insert_head(Circle_dullinklist &L, Elemtype e)
{
    // 判断链表是否存在
    if (Empty(L))
    {
        cout << "list not found" << endl;
        return;
    }
    Circle_dullinklist new_node = (Circle_dullinklist)malloc(sizeof(Dulnode));
    if (!new_node)
    {
        cout << "malloc error" << endl;
        return;
    }
    Circle_dullinklist p = L;
    while (p->next != L)
    {
        p = p->next;
    }
    p->next = new_node;
    new_node->prior = p;
    new_node->data = e;
    new_node->next = L;
    L->prior = new_node;
    // 更新头节点位置
    L = new_node;
    return;
}

// 尾插法
void Insert_last(Circle_dullinklist &L, Elemtype e)
{
    // 判断链表是否存在
    if (Empty(L))
    {
        cout << "list not found" << endl;
        return;
    }
    Circle_dullinklist new_node = (Circle_dullinklist)malloc(sizeof(Dulnode));
    if (!new_node)
    {
        cout << "malloc error" << endl;
        return;
    }
    new_node->data = e;
    Circle_dullinklist p = L;
    while (p->next != L)
    {
        p = p->next;
    }
    p->next = new_node;
    new_node->prior = p;
    new_node->next = L;
    L->prior = new_node;
    return;
}

// 在位置i前插入元素
void Insert_elem(Circle_dullinklist &L, int i, Elemtype e)
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
    Circle_dullinklist new_node = (Circle_dullinklist)malloc(sizeof(Dulnode));
    if (!new_node)
    {
        cout << "malloc error" << endl;
        return;
    }
    new_node->data = e;
    Circle_dullinklist p1 = L, p2 = L; // p1为后指针，p2为前指针
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
void Delete_elem(Circle_dullinklist &L, int i)
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
    Circle_dullinklist p = L, kill_p, p2;
    if (i == 1)
    {
        Circle_dullinklist p = L, kill_p;
        while (p->next != L)
        {
            p = p->next;
        }
        kill_p = L;
        L = L->next;
        L->prior = p;
        p->next = L;
        kill_p->next = NULL;
        kill_p->prior = NULL;
        free(kill_p);
        return;
    }

    else if (i == n)
    {
        while (p->next != L)
        {
            p2 = p;
            p = p->next;
        }
        p2->next = L;
        L->prior = p2;
        p->prior = NULL;
        p->next = NULL;
        free(p);
        return;
    }
    i--;
    while (i)
    {
        p2 = p;
        p = p->next;
        i--;
    }
    p->next->prior = p2;
    p2->next = p->next;
    p->next = NULL;
    p->prior = NULL;
    free(p);
    return;
}

// 寻找某元素第一次出现的位置，若链表不存在或元素不存在则返回-1
int Find_elem(Circle_dullinklist &L, Elemtype e)
{
    // 判断链表是否存在
    if (Empty(L))
    {
        cout << "list not found" << endl;
        return -1;
    }
    Circle_dullinklist p = L;
    if (p->data == e)
    {
        return 1;
    }
    p = p->next;
    int pos = 2;
    while (p != L)
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
void Destroy_list(Circle_dullinklist &L)
{
    // 判断链表是否存在
    if (Empty(L))
    {
        cout << "list not found" << endl;
        return;
    }
    Circle_dullinklist p = L, temp = L;
    p->prior->next = NULL;
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

// 顺序打印打印双向循环链表
void Print_list_ordered(Circle_dullinklist &L)
{
    // 判断链表是否存在
    if (Empty(L))
    {
        cout << "list no found" << endl;
        return;
    }
    Circle_dullinklist p = L;
    cout << p->data << ' ';
    p = p->next;
    while (p != L)
    {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
    return;
}

// 倒序打印双向循环链表
void Print_list_reversed(Circle_dullinklist &L)
{
    // 判断链表是否存在
    if (Empty(L))
    {
        cout << "list no found" << endl;
        return;
    }
    Circle_dullinklist p = L->prior;
    while (p != L)
    {
        cout << p->data << ' ';
        p = p->prior;
    }
    cout << p->data << ' ';
    cout << endl;
    return;
}