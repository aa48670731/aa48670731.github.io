#include <string>
using namespace std;
// class Solution
// {
// public:
//     string clearDigits(string s)
//     {
//         string res;
//         int n = s.size();
//         for (int i = 0; i < n; i++)
//         {
//             if (isdigit(s[i]))
//             {
//                 res.pop_back();
//             }
//             else
//             {
//                 res.push_back(s[i]);
//             }
//         }
//         return res;
//     }
// };
class Solution
{
public:
    string clearDigits(string s)
    {
        string res;
        for (char ch : s)
        {
            if (isdigit(ch))
            {
                res.pop_back();
            }
            else
            {
                res.push_back(ch);
            }
        }
        return res;
    }
};