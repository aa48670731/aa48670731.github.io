#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    string clearDigits(string s)
    {
        int n = s.size();
        vector<char> chs;
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                chs.push_back(s[i]);
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                if (!chs.empty())
                {
                    chs.pop_back();
                }
            }
        }
        string res;
        n = chs.size();
        for (int i = 0; i < n; i++)
        {
            res += chs[i];
        }
        return res;
    }
};

// class Solution
// {
// public:
//     string clearDigits(string s)
//     {
//         int n = s.size();
//         vector<char> chs;
//         for (int i = 0; i < n; i++)
//         {
//             if (s[i] >= 'a' && s[i] <= 'z')
//             {
//                 chs.push_back(s[i]);
//             }
//             else if (s[i] >= '0' && s[i] <= '9')
//             {
//                 if (!chs.empty())
//                 {
//                     chs.pop_back();
//                 }
//             }
//         }
//         string res;
//         return res.assign(chs.data(), chs.size());
//     }
// };