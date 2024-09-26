#include <vector>
#include <unordered_set>
#define MAX(A, B) (A > B ? A : B)
using namespace std;
class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        long long int n = nums.size(), tmp = 0, ans = 0;
        unordered_set<int> found;
        int right = 0, left = 0;
        for (; right < n; right++)
        {
            while (found.find(nums[right]) != found.end())
            {
                tmp -= nums[left];
                found.erase(nums[left]);
                left++;
            }
            found.insert(nums[right]);
            tmp += nums[right];
            while (right - left + 1 > k)
            {
                tmp -= nums[left];
                found.erase(nums[left]);
                left++;
            }
            if (right - left + 1 == k)
            {
                ans = MAX(ans, tmp);
            }
        }
        return ans;
    }
};