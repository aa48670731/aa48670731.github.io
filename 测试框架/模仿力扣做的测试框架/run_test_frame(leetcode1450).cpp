#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
using namespace std;

// ***替换函数处***
int find_querytime_people(vector<int> &starttime, vector<int> &endtime, int querytime)
{
    int count = 0, n = starttime.size();
    for (int i = 0; i < n; i++)
    {
        if (starttime[i] <= querytime && querytime <= endtime[i])
        {
            count++;
        }
    }
    return count;
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
        int n, querytime;
        ss >> n;
        vector<int> array1(n), array2(n);
        for (int i = 0; i < n; ++i)
        {
            ss >> array1[i];
        }
        for (int i = 0; i < n; ++i)
        {
            ss >> array2[i];
        }
        ss >> querytime;

        // 解析期望输出(***针对不同题目修改处***)
        int expected_value;
        ss >> expected_value; // 针对值相等比较
        // vector<int> expected_sorted_array(n);//针对数组相等比较
        // for (int i = 0; i < n; ++i)
        // {
        //     ss >> expected_sorted_array[i];
        // }

        // 运行待测函数（***针对不同题目修改处***）
        int test_value = find_querytime_people(array1, array2, querytime);
        // vector<int> sorted_array = sort_array(array);

        // 检查结果（***针对不同题目修改处***）
        if (test_value == expected_value)
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