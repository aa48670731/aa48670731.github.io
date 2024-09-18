#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        vector<int> ans;
        int n = nums.size();
        long long int summary = 0;
        if (1 + 2 * k > n)
        {
            for (int i = 0; i < n; i++)
            {
                ans.push_back(-1);
            }
            return ans;
        }
        for (int i = 0; i < k; i++)
        {
            ans.push_back(-1);
            summary += nums[i];
        }
        for (int i = k; i < 2 * k; i++)
        {
            summary += nums[i];
        }
        for (int left = 0, right = 2 * k; right < n; right++)
        {
            summary += nums[right];
            ans.push_back(summary / (right - left + 1));
            summary -= nums[left++];
        }
        for (int i = 0; i < k; i++)
        {
            ans.push_back(-1);
        }

        return ans;
    }
};