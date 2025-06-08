#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string reverseParentheses(string s) {
    int len = s.length();
    vector<int> pair(len);
    stack<int> p;
    for (int i = 0; i < len; ++i) {
        if (s[i] == '(') {
            p.push(i);
        } else if (s[i] == ')') {
            int j = p.top();
            p.pop();
            pair[i] = j;
            pair[j] = i;
        }
    }

    string ret;
    int index = 0, step = 1;
    while (index < len) {
        if (s[index] == '(' || s[index] == ')') {
            index = pair[index];
            step *= -1;
        } else {
            ret.push_back(s[index]);
        }

        index += step;
    }

    return ret;
}


int main() {
    cout << reverseParentheses("a(bcdefghijkl(mno)p)q") << endl;
    cout << reverseParentheses("(ed(et(oc))el)") << endl;
    cout << reverseParentheses("(u(love)i)") << endl;
    return 0;
}