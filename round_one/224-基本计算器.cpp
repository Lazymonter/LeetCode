/*
栈
+\-运算括号不影响最终结果，运算符可直接与运算数结合
可用栈记录括号之前的符号
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int calculate(string s) {
    stack<int> ops;
    ops.push(1);
    int sign = 1;

    int ret = 0, len = s.length();
    int i = 0;
    while (i < len) {
        if (s[i] == ' ') {
            i++;
        } else if (s[i] == '+') {
            sign = ops.top();
            i++;
        } else if (s[i] == '-') {
            sign = -ops.top();
            i++;
        } else if (s[i] == '(') {
            ops.push(sign);
            i++;
        } else if (s[i] == ')') {
            ops.pop();
            i++;
        } else {
            long num = 0;
            while (i < len && s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
                i++;
            }
            ret += sign * num;
        }
    }
    
    return ret;
}

int main() {
    string s = "(1+(4+5+2)-3)+(6+8)";
    cout << calculate(s) << endl;
    return 0;
}