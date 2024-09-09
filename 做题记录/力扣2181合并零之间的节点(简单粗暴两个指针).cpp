#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {
        head = head->next;
        ListNode *p1 = head, *p2 = head;
        while (1)
        {
            if (p2->next->val == 0)
            {
                if (p2->next->next == NULL)
                {
                    p1->next = NULL;
                    break;
                }
                else
                {
                    p2 = p2->next->next;
                    p1->next = p2;
                    p1 = p2;
                }
            }
            else
            {
                p2 = p2->next;
                p1->val += p2->val;
            }
        }
        return head;
    }
};