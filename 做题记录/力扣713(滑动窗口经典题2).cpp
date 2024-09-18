#include <vector>
using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k <= 1)
        {
            return 0;
        }
        int ans = 0, prod = 1;
        for (int left = 0, right = 0; right < n; right++)
        {
            prod *= nums[right];
            while (prod >= k)
            {
                prod /= nums[left++];
            }
            ans += right - left + 1;
        }
        return ans;
    }
};
