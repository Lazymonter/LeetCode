/*
栈
c++ string本身就实现了栈因此可以直接用，有些语言需要用栈过度
消除一对重复项可能会导致新的重复项出现，因此需要一个结构保存还未删除的字符
*/
#include <iostream>
#include <string>

using namespace std;

string removeDuplicates(string S) {
    string ret = "";
    for (auto &c : S) {
        if (ret.empty() || ret.back() != c) {
            ret.push_back(c);
        } else {
            ret.pop_back();
        }
    }
    
    return ret;
    
}

int main() {
    string s = "abbaca";
    cout << removeDuplicates(s) << endl;
    return 0;
}