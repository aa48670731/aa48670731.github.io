#include <vector>
#define MIN(A, B) (A < B ? A : B)
using namespace std;
// 自己想的慢办法
//  class Solution
//  {
//  public:
//      int timeRequiredToBuy(vector<int> &tickets, int k)
//      {
//          int count = 0, n = tickets.size();
//          for (int i = 0; i < n; i++)
//          {
//              if (i <= k)
//              {
//                  count += tickets[i] > tickets[k] ? tickets[k] : tickets[i];
//              }
//              else
//              {
//                  count += tickets[i] >= tickets[k] ? tickets[k] - 1 : tickets[i];
//              }
//          }
//          return count;
//      }
//  };

// 精简
class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int count = 0, n = tickets.size();
        for (int i = 0; i < n; i++)
        {
            count += MIN(tickets[k] - (i > k), tickets[i]);
        }
        return count;
    }
};