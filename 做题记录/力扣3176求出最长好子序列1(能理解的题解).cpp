#include <vector>
using namespace std;
class Solution
{
public:
    int maximumLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        // 定义 dp 数组，dp[i][j] 表示考虑前 i+1 个元素且有 j 个不同元素对的最大子序列长度
        vector<vector<int>> dp(n, std::vector<int>(k + 1, 0));

        // 初始化，当没有不同元素对时（j=0），任何单独的元素都是长度为 1 的有效子序列
        for (int i = 0; i < n; ++i)
        {
            dp[i][0] = 1;
        }

        int ans = 0; // 初始化答案变量
        // 计算 dp 数组
        for (int i = 0; i < n; ++i)
        { // 遍历每个元素
            for (int j = 0; j <= k; ++j)
            { // 考虑 0 到 k 个不同元素对的情况
                for (int l = 0; l < i; ++l)
                { // 遍历之前的所有元素
                    if (nums[i] == nums[l])
                    { // 如果当前元素与前面某个元素相同
                        // 更新 dp[i][j] 的值，取最大值
                        dp[i][j] = std::max(dp[i][j], dp[l][j] + 1);
                    }
                    else if (j > 0)
                    { // 如果还有剩余的不同元素对可以使用
                        // 更新 dp[i][j] 的值，取最大值
                        dp[i][j] = std::max(dp[i][j], dp[l][j - 1] + 1);
                    }
                }
                // 更新答案，取最大值
                ans = std::max(ans, dp[i][j]);
            }
        }
        return ans; // 返回最长的好子序列长度
    }
};