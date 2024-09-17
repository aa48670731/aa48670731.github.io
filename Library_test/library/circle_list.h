#include <iostream>
#include <malloc.h>
using namespace std;

typedef int Elemtype;

typedef struct Node
{
    Elemtype data;
    struct Node *next;
} Node, *Circle_list;

// 初始化
void Init_circle_list(Circle_list &L, Elemtype e)
{
    Circle_list newbase = (Circle_list)malloc(sizeof(Node));
    if (!newbase)
    {
        cout << "malloc error" << endl;
        return;
    }
    L = newbase;
    // 头指针一般没有数据
    L->data = e;
    // 初始化头指针指向
    L->next = L;
    return;
}

// 获取循环链表长度
int List_length(Circle_list &L)
{
    // 判断链表是否存在
    if (!L)
    {
        cout << "list no found" << endl;
        return -1;
    }
    int count = 1;
    Circle_list p = L->next;
    while (p != L)
    {
        p = p->next;
        count++;
    }
    return count;
}

// 头插法
void Insert_head(Circle_list &L, Elemtype e)
{
    // 判断链表是否存在
    if (!L)
    {
        cout << "list no found" << endl;
        return;
    }
    Circle_list new_node = (Circle_list)malloc(sizeof(Node));
    if (!new_node)
    {
        cout << "malloc error" << endl;
        return;
    }
    new_node->data = e;
    Circle_list p = L;
    while (p->next != L)
    {
        p = p->next;
    }
    p->next = new_node;
    new_node->next = L;
    L = new_node;
    return;
}

// 尾插法
void Insert_last(Circle_list &L, Elemtype e)
{
    // 判断链表是否存在
    if (!L)
    {
        cout << "list no found" << endl;
        return;
    }
    Circle_list new_node = (Circle_list)malloc(sizeof(Node));
    if (!new_node)
    {
        cout << "malloc error" << endl;
        return;
    }
    new_node->data = e;
    Circle_list p = L;
    while (p->next != L)
    {
        p = p->next;
    }
    p->next = new_node;
    new_node->next = L;
    return;
}

// 在位置i前插入元素
void Insert_elem(Circle_list &L, int i, Elemtype e)
{
    // 判断链表是否存在
    if (!L)
    {
        cout << "list no found" << endl;
        return;
    }
    int n = List_length(L);
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
    else if (i == n + 1)
    {
        Insert_last(L, e);
        return;
    }
    Circle_list p1 = L, p2 = L;
    i--;
    while (i)
    {
        p2 = p1;
        p1 = p1->next;
        i--;
    }
    Circle_list new_node = (Circle_list)malloc(sizeof(Node));
    if (!new_node)
    {
        cout << "malloc error" << endl;
        return;
    }
    new_node->data = e;
    p2->next = new_node;
    new_node->next = p1;
    return;
}

// 删除某位置的值
void Delete_elem(Circle_list &L, int i)
{
    // 判断链表是否存在
    if (!L)
    {
        cout << "list no found" << endl;
        return;
    }
    int n = List_length(L);
    if (i <= 0 || i > n)
    {
        cout << "position error" << endl;
        return;
    }
    Circle_list p1 = L, p2 = L;
    if (i == 1)
    {
        p1 = p1->next;
        while (p1 != L)
        {
            p2 = p1;
            p1 = p1->next;
        }
        L = L->next;
        p2->next = L;
        p1->next = NULL;
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
    p2->next = p1->next;
    p1->next = NULL;
    free(p1);
    return;
}

// 获取位置i的值
Elemtype Get_elem(Circle_list &L, int i)
{
    // 判断链表是否存在
    if (!L)
    {
        cout << "list no found" << endl;
        return -1;
    }
    int n = List_length(L);
    if (i <= 0 || i > n)
    {
        cout << "position error" << endl;
        return -1;
    }
    Circle_list p = L;
    i--;
    while (i)
    {
        p = p->next;
        i--;
    }
    return p->data;
}

// 输出循环链表
void Print_list(Circle_list &L)
{
    // 判断链表是否存在
    if (!L)
    {
        cout << "list no found" << endl;
        return;
    }
    Circle_list p = L;
    cout << p->data << " ";
    p = p->next;
    while (p != L)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    return;
}

// 销毁循环链表
void Destroy_list(Circle_list &L)
{
    Circle_list temp = L->next;
    Circle_list p = L->next->next;
    while (p != L)
    {
        temp->next = NULL;
        free(temp);
        temp = p;
        p = p->next;
    }
    if (temp == L)
    {
        free(L);
        L = NULL;
        return;
    }
    temp->next = NULL;
    free(temp);
    L->next = NULL;
    free(L);
    L = NULL;
    return;
}

// 判断链表是否为循环链表
void Judge_circle_list(Circle_list &L)
{
    Circle_list p1 = L, p2 = L;
    while (p1 && p2)
    {
        p1 = p1->next;
        p2 = p2->next->next;
        if (p1 == p2)
        {
            cout << "The list is a Circle list" << endl;
            return;
        }
    }
    cout << "The list is not a Circle list" << endl;
}
