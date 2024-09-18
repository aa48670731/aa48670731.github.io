#include <vector>
#define MIN(A, B) (A < B ? A : B)
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int ans = n + 1, summary = 0;
        for (int left = 0, right = 0; right < n; right++)
        {
            summary += nums[right];
            while (summary >= target)
            {
                ans = MIN(ans, right - left + 1);
                summary -= nums[left];
                left++;
            }
        }

        return (ans == n + 1 ? 0 : ans);
    }
};