#include <vector>
#include <algorithm>
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
                    for (int j = i + 1; j < n; j++)
                    {
                        if (i + 1 < nums[j])
                        {
                            count++;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
        return count;
    }
};