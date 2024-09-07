class Solution
{
public:
    int climbStairs(int n)
    {
        // 动态规划
        if (n == 1 || n == 2)
        {
            return n;
        }
        // 初始化状态
        int dp[50];
        dp[1] = 1;
        dp[2] = 2;
        // 状态更新方程
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};