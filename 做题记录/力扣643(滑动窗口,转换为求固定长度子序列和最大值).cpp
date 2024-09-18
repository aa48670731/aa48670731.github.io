#include <vector>
#define MAX(A, B) (A > B ? A : B)
using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        double ans = -10001, ave = 0, summary = 0;
        int n = nums.size();
        for (int i = 0; i < k; i++)
        {
            summary += nums[i];
        }
        ans = summary;
        for (int right = k; right < n; right++)
        {
            summary = summary + nums[right] - nums[right - k];
            ans = MAX(ans, summary);
        }
        return ans / k;
    }
};