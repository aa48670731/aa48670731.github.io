#include <string>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        string str = to_string(x);
        for (int left = 0, right = str.size() - 1; left <= right; left++, right--)
        {
            if (str[left] != str[right])
            {
                return false;
            }
        }
        return true;
    }
};