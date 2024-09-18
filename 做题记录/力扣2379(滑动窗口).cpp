#include <string>
#define MIN(A, B) (A < B ? A : B)
using namespace std;

class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int n = blocks.size(), ans = k, count = 0;
        for (int i = 0; i < k; i++)
        {
            if (blocks[i] == 'W')
            {
                count++;
            }
        }
        ans = MIN(ans, count);
        for (int left = 0, right = k; right < n; right++)
        {
            if (blocks[right] == 'W')
            {
                count++;
            }
            while (right - left + 1 > k)
            {
                if (blocks[left] == 'W')
                {
                    count--;
                }
                left++;
            }
            ans = MIN(ans, count);
        }
        return ans;
    }
};