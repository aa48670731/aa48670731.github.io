#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        vector<int> ans;
        int n = code.size();
        if (k == 0)
        {
            for (int i = 0; i < n; i++)
            {
                code[i] = 0;
            }
            return code;
        }
        if (k > 0)
        {
            int summary = 0;
            for (int i = 1; i < 1 + k; i++)
            {
                summary += code[i];
            }
            ans.push_back(summary);
            for (int i = 1, left = 1, right = 1 + k; i < n; i++, right++)
            {
                summary += code[right % n];
                summary -= code[left % n];
                left++;
                ans.push_back(summary);
            }
        }
        else // k<0
        {
            k = -k;
            int summary = 0;
            for (int i = n - 1; i > n - k - 1; i--)
            {
                summary += code[i];
            }
            ans.push_back(summary);
            for (int i = 1, right = 0, left = n - k; i < n; i++, right++)
            {
                summary += code[right];
                summary -= code[left % n];
                left++;
                ans.push_back(summary);
            }
        }
        return ans;
    }
};
