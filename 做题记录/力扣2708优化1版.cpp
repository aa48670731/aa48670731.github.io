#include <vector>
#include <algorithm>
using namespace std;
#define MAX(A, B) (A > B ? A : B)
class Solution
{
public:
    long long maxStrength(vector<int> &nums)
    {
        int neg_max = -1000000;
        long long int ans = 1;
        int neg_count = 0, pos_count = 0;
        int zeroflag = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {

            if (nums[i] < 0)
            {
                neg_max = MAX(neg_max, nums[i]);
                neg_count++;
            }
            else if (nums[i] > 0)
            {
                pos_count++;
            }
            if (nums[i] != 0)
            {
                ans *= nums[i];
            }
            else
            {
                zeroflag = 1;
            }
        }
        if (neg_count <= 1 && pos_count == 0 && zeroflag == 1)
        {
            return 0;
        }
        else if (neg_count == 1 && pos_count == 0 && zeroflag == 0)
        {
            return ans;
        }

        return ans > 0 ? ans : ans / neg_max;
    }
};