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
        int pred, last;
        pred = 1;
        last = 2;
        // 状态更新方程
        for (int i = 3; i <= n; i++)
        {
            // 利用滚动变量来优化空间
            int mid = last;
            last = pred + mid;
            pred = mid;
        }
        return last;
    }
};