#include <iostream>
using namespace std;
int start = 0, last = 0;
int findmaxsonarray(int num[], int n)
{
    int tempstart = 0;
    int currentmax = num[0];
    int globalmax = num[0];
    for (int i = 1; i < n; i++)
    {
        if (num[i] > currentmax + num[i])
        {
            currentmax = num[i];
            tempstart = i;
        }
        else if (currentmax + num[i] > num[i])
        {
            currentmax = currentmax + num[i];
        }
        else
        {
            currentmax = num[i];
        }
        if (currentmax > globalmax)
        {
            globalmax = currentmax;
            start = tempstart;
            last = i;
        }
    }
    return globalmax;
}

int main()
{
    int n;
    while (cin >> n)
    {
        int a[100005];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int res = findmaxsonarray(a, n);
        if (res < 0)
        {
            // res<0时易知
            cout << 0 << ' ' << -1 << ' ' << -1 << endl;
            // 本体要求全部整数为负数时，最大子序列的长度为0，此时起止位置都设置为-1
        }
        else
        {
            cout << res << ' ' << start << ' ' << last << endl;
        }
    }
    return 0;
}
