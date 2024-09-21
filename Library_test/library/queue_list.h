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

// 队列定义
typedef struct Queue
{
    Listnode front = NULL; // 队头
    Listnode rear = NULL;  // 队尾
    int length = 0;        // 长度
} Queue;

// 判空
int Empty(Queue &Q)
{
    return (Q.rear == NULL);
}
// 获取长度
int Length(Queue &Q)
{
    if (Empty(Q))
    {
        cout << "queue is not found" << endl;
        return -1;
    }
    return Q.length;
}

// 初始化队列
void Init_queue(Queue &Q, Elemtype e)
{
    Listnode new_node = (Listnode)malloc(sizeof(Node));
    if (!new_node)
    {
        cout << "malloc error" << endl;
        return;
    }
    new_node->data = e;
    new_node->next = NULL;
    Q.front = new_node;
    Q.rear = new_node;
    Q.length++;
    return;
}

// 入队
void push(Queue &Q, Elemtype e)
{
    if (Empty(Q))
    {
        cout << "queue is not found" << endl;
        return;
    }
    Listnode new_node = (Listnode)malloc(sizeof(Node));
    if (!new_node)
    {
        cout << "malloc error" << endl;
        return;
    }
    new_node->data = e;
    new_node->next = NULL;
    Q.rear->next = new_node;
    Q.rear = new_node;
    Q.length++;
    return;
}

// 出队
Elemtype pop(Queue &Q)
{
    if (Empty(Q))
    {
        cout << "queue is not found" << endl;
        return INT32_MIN;
    }

    Elemtype val = Q.front->data;
    Listnode p = Q.front;
    Q.front = Q.front->next;
    p->next = NULL;
    free(p);
    Q.length--;
    return val;
}

// 打印队列
void Print_queue(Queue &Q)
{
    if (Empty(Q))
    {
        cout << "queue is not found" << endl;
        return;
    }
    Listnode p = Q.front;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    return;
}

// 销毁队列
void Destroy_queue(Queue &Q)
{
    if (Empty(Q))
    {
        cout << "queue is not found" << endl;
        return;
    }
    Listnode p;
    while (Q.front)
    {
        p = Q.front;
        Q.front = Q.front->next;
        p->next = NULL;
        free(p);
    }
    Q.rear = NULL;
    return;
}
