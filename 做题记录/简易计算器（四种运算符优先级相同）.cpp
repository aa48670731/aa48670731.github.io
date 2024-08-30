#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string temp;
    int n, j, number, result = 0, flag = 1;
    cin >> temp;
    n = temp.length();
    char op; // 上一个地方读取到的操作符
    number = temp[0] - 48;
    j = 1;
    while (temp[j] >= '0' && temp[j] <= '9')
    {
        number = number * 10 + temp[j] - 48;
        j++;
    }
    result += number;
    for (int i = j; i <= n; i++)
    {
        if (temp[i] == '=')
        {
            break;
        }
        else if (temp[i] >= '0' && temp[i] <= '9')
        {
            number = temp[i] - 48;
            j = i + 1;
            while (temp[j] >= '0' && temp[j] <= '9')
            {
                number = number * 10 + temp[j] - 48;
                j++;
            }
            if (op == '+')
            {
                result += number;
            }
            else if (op == '-')
            {
                result -= number;
            }
            else if (op == '*')
            {
                result *= number;
            }
            else if (op == '/')
            {
                if (number == 0)
                {
                    flag = 0;
                    break;
                }
                result /= number;
            }
            i = j - 1; // 更新i值
        }
        else if (temp[i] == '+')
        {
            op = '+';
        }
        else if (temp[i] == '-')
        {
            op = '-';
        }
        else if (temp[i] == '*')
        {
            op = '*';
        }
        else if (temp[i] == '/')
        {
            op = '/';
        }
        else
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        cout << result;
    }
    else
    {
        cout << "ERROR";
    }
    return 0;
}
