#include <unordered_set>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution // 快慢指针判断入口，有一点注意：快指针走的路程任何时候都是慢指针的两倍
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                while (slow != head)
                {
                    head = head->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};

// class Solution//哈希表法，无脑简单
// {
// public:
//     ListNode *detectCycle(ListNode *head)
//     {
//         unordered_set<ListNode *> dic;
//         ListNode *p = head;
//         while (p != nullptr)
//         {
//             if (dic.find(p) != dic.end())
//             {
//                 return p;
//             }
//             dic.insert(p);
//             p = p->next;
//         }
//         return nullptr;
//     }
// };