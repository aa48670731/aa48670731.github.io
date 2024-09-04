#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int countWays(vector<int> &nums)
    {
        int count = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        if (nums[0] != 0)
        {
            count++;
        }
        for (int i = 0; i < n; i++)
        {
            if (i + 1 > nums[i])
            {
                if (i + 1 >= n)
                {
                    count++;
                }
                else
                {
                    if (i + 1 < nums[i + 1])
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};