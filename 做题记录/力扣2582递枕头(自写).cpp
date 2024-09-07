class Solution
{
public:
    int passThePillow(int n, int time)
    {
        time %= ((n - 1) * 2);
        int ans = 1;
        if (time >= n - 1)
        {
            time -= n - 1;
            ans = n;
            for (int i = 0; i < time; i++)
            {
                ans--;
            }
        }
        else
        {
            for (int i = 0; i < time; i++)
            {
                ans++;
            }
        }
        return ans;
    }
};