#include <iostream>
#include <vector>
using namespace std;
#define MAX(a, b) (a > b ? a : b)
void find_max_subarray(int n, const vector<int> &array)
{
    int max_sum = 0;
    int current_sum = 0;
    int start = 0, end = 0, temp_start = 0;

    for (int i = 0; i < n; ++i)
    {
        current_sum += array[i];

        if (current_sum > max_sum)
        {
            max_sum = current_sum;
            start = temp_start;
            end = i;
        }

        if (current_sum < 0)
        {
            current_sum = 0;
            temp_start = i + 1;
        }
    }

    if (max_sum == 0)
    {
        cout << "0 -1 -1" << endl;
    }
    else
    {
        cout << max_sum << " " << start + 1 << " " << end + 1 << endl;
    }
}

int findmaxsonarray(int num[], int n)
{
    int currentmax = num[0];
    int globalmax = num[0];
    for (int i = 1; i < n; i++)
    {
        currentmax = MAX(num[i], currentmax + num[i]);
        globalmax = MAX(globalmax, currentmax);
    }
    return globalmax;
}

int main()
{
    int n;
    while (cin >> n)
    {
        int a[1000];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int res = findmaxsonarray(a, n);
        cout << res << endl;
    }
    return 0;
}
