#define MAX(A, B) (A > B ? A : B)
class Solution
{
public:
    long long maxStrength(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        int neg_max = -10;
        long long int ans = 1;
        int count = 0;
        for (int i = 0, n = nums.size(); i < n; i++)
        {
            int num = nums[i];
            if (num)
            {
                ans *= num;
                count++;
            }
            if (nums[i] < 0)
            {
                neg_max = MAX(neg_max, nums[i]);
            }
        }
        if (!count || (count == 1 && ans < 0))
        {
            return 0;
        }
        return ans > 0 ? ans : ans / neg_max;
    }
};