#include <iostream>
#include <vector>
#define MAX(A, B) (A > B ? A : B)
using namespace std;

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
