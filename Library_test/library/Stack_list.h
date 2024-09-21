#include <iostream>
#include <vector>
#include <malloc.h>
using namespace std;

typedef int Elemtype;

// 链表节点定义
typedef struct Node
{
    Elemtype data;
    struct Node *next;
} Node, *Listnode;

// 栈定义
typedef struct Stack
{
    Listnode top = NULL;
    int length;
} Stack;

// 判空
int Empty(Stack &S)
{
    return (S.top == NULL);
}

// 返回长度
int Length(Stack &S)
{
    if (Empty(S))
    {
        cout << "stack not found" << endl;
        return -1;
    }
    return S.length;
}

// 初始化栈
void Init_stack(Stack &S, Elemtype e)
{
    Listnode newbase = (Listnode)malloc(sizeof(Node));
    if (!newbase)
    {
        cout << "malloc error" << endl;
        return;
    }
    newbase->data = e;
    newbase->next = NULL;
    S.top = newbase;
    S.length = 1;
    return;
}

// 返回栈顶元素
Elemtype peek(Stack &S)
{
    if (Empty(S))
    {
        cout << "Stack is empty" << endl;
        return INT32_MIN;
    }
    return S.top->data;
}

// 入栈
void push(Stack &S, Elemtype e)
{
    Listnode new_node = (Listnode)malloc(sizeof(Node));
    new_node->data = e;
    new_node->next = S.top;
    S.top = new_node;
    S.length++;
    return;
}

// 出栈
Elemtype pop(Stack &S)
{
    if (Empty(S))
    {
        cout << "Stack is empty" << endl;
        return INT32_MIN;
    }
    Elemtype val = peek(S);
    Listnode p = S.top;
    S.top = S.top->next;
    p->next = NULL;
    free(p);
    S.length--;
    return val;
}

// 打印栈
void Print_stack(Stack &S)
{
    if (Empty(S))
    {
        cout << "Stack is empty" << endl;
        return;
    }
    vector<Elemtype> stack(S.length);
    Listnode p = S.top;
    int n = S.length;
    for (int i = n - 1; i >= 0; i--)
    {
        stack[i] = p->data;
        p = p->next;
    }

    for (int i = 0; i < n; i++)
    {
        cout << stack[i] << ' ';
    }
    cout << endl;
    return;
}

// 销毁栈
void Destroy_stack(Stack &S)
{
    Listnode p;
    while (S.top)
    {
        p = S.top;
        S.top = S.top->next;
        p->next = NULL;
        free(p);
    }
    return;
}
