#include <vector>
#define MAX(A, B) (A > B ? A : B)
using namespace std;

class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int n = values.size();
        int ans = 0, tmp = 0;
        int right = 1, left = 0;
        for (; right < n; right++)
        {
            tmp = values[left] + values[right] + left - right;
            ans = MAX(ans, tmp);
            if (right + values[right] > values[left] + left)
            {
                left = right;
            }
        }
        return ans;
    }
};