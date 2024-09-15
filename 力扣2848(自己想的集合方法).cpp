#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution
{
public:
    int numberOfPoints(vector<vector<int>> &nums)
    {
        int n = nums.size();
        set<int> points;
        for (int i = 0; i < n; i++)
        {
            int m = nums[i][1];
            for (int j = nums[i][0]; j <= m; j++)
            {
                points.insert(j);
            }
        }
        return points.size();
    }
};