#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    long long maxStrength(vector<int> &nums)
    {
        vector<int> neg_array, pos_array;
        long long int ans = 1;
        int zero = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
            {
                neg_array.push_back(nums[i]);
            }
            else if (nums[i] > 0)
            {
                pos_array.push_back(nums[i]);
            }
            else
            {
                zero = 1;
            }
        }
        int pos_n = pos_array.size(), neg_n = neg_array.size();
        if (pos_n == 0 && neg_n <= 1 && zero == 1)
        {
            return 0;
        }
        else if (neg_n == 1 && pos_n == 0 && zero == 0)
        {
            return neg_array[0];
        }
        else if (neg_n % 2 == 0)
        {
            for (int i = 0; i < pos_n; i++)
            {
                ans *= pos_array[i];
            }
            for (int i = 0; i < neg_n; i++)
            {
                ans *= neg_array[i];
            }
            return ans;
        }
        else if (neg_n < 2 && pos_n != 0)
        {
            for (int i = 0; i < pos_n; i++)
            {
                ans *= pos_array[i];
            }
            return ans;
        }
        else if (neg_n >= 2)
        {
            sort(neg_array.begin(), neg_array.end());
            for (int i = 0; i < pos_n; i++)
            {
                ans *= pos_array[i];
            }
            for (int i = 0; i < neg_n - 1; i++)
            {
                ans *= neg_array[i];
            }
        }
        return ans;
    }
};