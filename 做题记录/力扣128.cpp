#define MAX(A, B) (A > B ? A : B)
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (!n)
        {
            return 0;
        }
        int count = 1;
        int max_count = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1] + 1)
            {
                count++;
                max_count = MAX(max_count, count);
            }
            else if (nums[i] == nums[i - 1])
            {
                continue;
            }
            else
            {
                count = 1;
            }
        }
        return max_count;
    }
};