class Solution
{
public:
    int numberOfChild(int n, int k)
    {
        k %= ((n - 1) * 2);
        int ans = 0;
        if (k >= n - 1)
        {
            k -= n - 1;
            ans = n - 1;
            for (int i = 0; i < k; i++)
            {
                ans--;
            }
        }
        else
        {
            for (int i = 0; i < k; i++)
            {
                ans++;
            }
        }
        return ans;
    }
};