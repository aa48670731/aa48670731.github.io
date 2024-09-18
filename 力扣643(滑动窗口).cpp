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
        for (int i = 0; i < k - 1; i++)
        {
            summary += nums[i];
        }
        for (int left = 0, right = k - 1; right < n; right++)
        {
            summary += nums[right];
            ave = summary / k;
            ans = MAX(ans, ave);
            summary -= nums[left++];
        }
        return ans;
    }
};