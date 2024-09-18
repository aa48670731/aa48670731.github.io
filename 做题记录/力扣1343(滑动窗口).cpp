#include <vector>
using namespace std;

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        int n = arr.size(), ans = 0, check = threshold * k, summary = 0;
        for (int i = 0; i < k - 1; i++)
        {
            summary += arr[i];
        }
        for (int left = 0, right = k - 1; right < n; right++)
        {
            summary += arr[right];
            if (summary >= check)
            {
                ans++;
            }
            summary -= arr[left++];
        }
        return ans;
    }
};