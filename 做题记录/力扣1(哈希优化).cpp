#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        unordered_map<int, int> map;
        int i, j;
        for (int i = 0; i < n; i++)
        {
            if (map.find(target - nums[i]) != map.end())
            {
                return {map[target - nums[i]], i};
            }
            map.emplace(nums[i], i);
        }
        return {i, j};
    }
};