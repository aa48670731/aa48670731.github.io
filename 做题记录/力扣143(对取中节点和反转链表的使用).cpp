#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 该题目可以看做对中间节点和反转节点的综合使用

ListNode *get_midnode(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *reverse_list(ListNode *head)
{
    ListNode *pre = nullptr, *cur = head;
    while (cur)
    {
        ListNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        ListNode *head1 = head, *p2 = nullptr;
        p2 = get_midnode(head);
        ListNode *head2 = reverse_list(p2);
        while (head2->next)
        {
            ListNode *next1 = head1->next, *next2 = head2->next;
            head1->next = head2;
            head2->next = next1;
            head1 = next1;
            head2 = next2;
        }
    }
};
