#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

// ***替换函数处***
int find_max_value(const vector<int> &array)
{
    int m = array[0], n = array.size();
    for (int i = 0; i < n; i++)
    {
        if (m < array[i])
        {
            m = array[i];
        }
    }
    return m;
}

// 执行用例函数
void run_tests(const string &test_file)
{
    ifstream infile(test_file);
    if (!infile)
    {
        cerr << "无法打开测试文件。" << endl;
        return;
    }

    int total_tests = 0;
    int correct_tests = 0;

    string line;
    while (getline(infile, line))
    {
        if (line.empty())
            continue;

        // 解析输入
        stringstream ss(line);
        int n;
        ss >> n;
        vector<int> array(n);
        for (int i = 0; i < n; ++i)
        {
            ss >> array[i];
        }

        // 解析期望输出
        int expected_max_value;
        ss >> expected_max_value;

        // 运行待测函数（***针对不同题目修改处***）
        int max_value = find_max_value(array);

        // 检查结果（***针对不同题目修改处***）
        if (max_value == expected_max_value)
        {
            correct_tests++;
        }
        total_tests++;
    }

    infile.close();

    // 输出结果
    cout << "测试用例总数: " << total_tests << endl;
    cout << "正确的测试用例: " << correct_tests << endl;
    cout << "正确率: " << (correct_tests * 100.0 / total_tests) << "%" << endl;
}

int main()
{
    run_tests("test_cases.txt"); // 假设测试数据存储在 test_cases.txt 文件中
    return 0;
}
/*
测试数据写法：
第一部分对应输入多少个数据，
第二部分对应输入的实际数据，
第三部分对应期望输出
*/