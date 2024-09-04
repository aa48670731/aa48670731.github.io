#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> num_set;
        for (const int &num : nums)
        {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (const int &num : num_set)
        {
            if (!num_set.count(num - 1))
            {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1))
                {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};

/*作者：力扣官方题解
链接：https : // leetcode.cn/problems/longest-consecutive-sequence/solutions/276931/zui-chang-lian-xu-xu-lie-by-leetcode-solution/
              来源：力扣（LeetCode） 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/