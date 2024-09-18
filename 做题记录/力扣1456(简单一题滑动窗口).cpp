#include <string>
#define MAX(A, B) (A > B ? A : B)
using namespace std;
class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int ans = 0, n = s.size(), summary = 0;
        for (int left = 0, right = 0; right < n; right++)
        {
            if (s[right] == 'a' || s[right] == 'e' || s[right] == 'i' || s[right] == 'o' || s[right] == 'u')
            {
                summary++;
            }
            while (right - left + 1 > k)
            {
                if (s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] == 'o' || s[left] == 'u')
                {
                    summary--;
                }
                left++;
            }
            ans = MAX(ans, summary);
        }
        return ans;
    }
};