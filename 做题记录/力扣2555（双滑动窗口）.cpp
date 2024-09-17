#include <vector>
#include <iostream>
#define MAX(A, B) (A > B ? A : B)
using namespace std;

class Solution
{
public:
    int maximizeWin(vector<int> &prizePositions, int k)
    {
        int ans = 0, n = prizePositions.size();
        // l==left,r==right
        for (int l1 = 0, r1 = 0, l2 = 0, r2 = 0, firstMax = 0; r2 < n; r2++)
        {
            while (prizePositions[r2] - prizePositions[l2] > k)
            {
                l2++;
            }
            for (; r1 < l2; r1++)
            {
                while (prizePositions[r1] - prizePositions[l1] > k)
                {
                    l1++;
                }
                firstMax = MAX(firstMax, r1 - l1 + 1);
            }
            ans = MAX(ans, r2 - l2 + 1 + firstMax);
        }
        return ans;
    }
};