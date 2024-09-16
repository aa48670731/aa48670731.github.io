#define MIN(A, B) (A < B ? A : B)
#include <vector>
using namespace std;

class Solution
{
public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination)
    {
        int ans = 0, ans_right = 0, ans_left = 0, n = distance.size();
        if (start > destination)
        {
            int temp = start;
            start = destination;
            destination = temp;
        }
        int i1 = start, i2 = start;
        while (i1 != destination && i2 != destination)
        {
            i2--;
            if (i1 >= n)
            {
                i1 -= n;
            }
            if (i2 < 0)
            {
                i2 += n;
            }
            ans_right += distance[i1];
            ans_left += distance[i2];
            i1++;
        }
        while (i1 != destination)
        {
            if (i1 >= n)
            {
                i1 -= n;
            }
            ans_right += distance[i1];
            i1++;
        }
        while (i2 != destination)
        {
            i2--;
            if (i2 < 0)
            {
                i2 += n;
            }
            ans_left += distance[i2];
        }
        ans = MIN(ans_right, ans_left);
        return ans;
    }
};