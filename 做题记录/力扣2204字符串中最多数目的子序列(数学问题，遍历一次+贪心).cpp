#include <vector>
#include <string>
#define MAX(A, B) (A > B ? A : B)
using namespace std;
class Solution
{
public:
    long long maximumSubsequenceCount(string text, string pattern)
    {
        long long int n = text.size(), m, temp_c = 0, temp_a = 0;
        long long int ans = 0, added = 0;
        vector<int> index;
        if (pattern[0] == pattern[1])
        {
            for (int i = 0; i < n; i++)
            {
                if (pattern[0] == text[i])
                {
                    temp_a++;
                }
            }
            temp_a++;
            return (temp_a * (temp_a - 1)) / 2;
        }
        for (int i = 0; i < n; i++)
        {
            if (text[i] == pattern[0])
            {
                added += 1;
                temp_a++;
            }
            else if (text[i] == pattern[1])
            {
                ans += added;
                temp_c++;
            }
        }
        return MAX(ans + temp_c, ans + temp_a);
    }
};