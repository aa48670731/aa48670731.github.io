#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        int left = n - 1, right = 0, flag = 0;
        if (nums[left] <= 0)
        {
            for (int i = left; i >= 0; i--)
            {
                ans.push_back(nums[i] * nums[i]);
            }
            return ans;
        } // 全是非正数的情况
        else if (nums[right] >= 0)
        {
            for (int i = right; i < n; i++)
            {
                ans.push_back(nums[i] * nums[i]);
            }
            return ans;
        } // 全是正数的情况
        // 有正有负的情况
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] <= 0 && nums[i + 1] > 0)
            {
                left = i;
                right = i + 1;
            }
        }
        while (left >= 0 && right < n)
        {
            int l_num = nums[left] * nums[left];
            int r_num = nums[right] * nums[right];
            if (l_num <= r_num)
            {
                ans.push_back(l_num);
                left--;
            }
            else
            {
                ans.push_back(r_num);
                right++;
            }
        }
        while (left >= 0)
        {
            ans.push_back(nums[left] * nums[left]);
            left--;
        }
        while (right < n)
        {
            ans.push_back(nums[right] * nums[right]);
            right++;
        }
        return ans;
    }
};