/*
栈
accumate()求元素和或者链接字符串
前两个参数是定义序列的输入迭代器，第三个参数是和的初值，
第 4 个参数是定义应用到总数和元素之间的二元函数对象
*/

#include <iostream>
#include <stack>
#include <string>
#include <numeric>
#include <vector>

using namespace std;

int calculate(string s) {
    vector<int> stk;
    char preSign = '+';
    int num = 0;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        if (isdigit(s[i])) {
            num = num * 10 + int(s[i] - '0');
        }
        if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
            switch (preSign) {
                case '+':
                    stk.push_back(num);
                    break;
                case '-':
                    stk.push_back(-num);
                    break;
                case '*':
                    stk.back() *= num;
                    break;
                default:
                    stk.back() /= num;
            }
            preSign = s[i];
            num = 0;
        }
    }
    return accumulate(stk.begin(), stk.end(), 0);
}

int main() {
    string s1 = "3+2* 2 -2";
    cout << calculate(s1) << endl;
    return 0;
}