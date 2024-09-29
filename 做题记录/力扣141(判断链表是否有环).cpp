#include <unordered_set>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{ // 快慢指针法
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};

// class Solution // 哈希表记录法
// {
// public:
//     bool hasCycle(ListNode *head)
//     {
//         unordered_set<ListNode *> dic;
//         ListNode *p = head;
//         while (p != nullptr)
//         {
//             if (dic.find(p) != dic.end())
//             {
//                 return true;
//             }
//             dic.insert(p);
//             p = p->next;
//         }
//         return false;
//     }
// };